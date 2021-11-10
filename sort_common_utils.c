#include "push_swap.h"

static int	issmall_exist(t_list *a, int tmp, int src)
{
	t_list	*lst;
	int		res;

	lst = a;
	res = 0;
	while (lst && res == 0)
	{
		if (lst->data < tmp && lst->data > src)
			res = 1;
		lst = lst->next;
	}
	return (res);
}

static void	helper(t_stacks *s, t_list *b, int *i, int *tmp)
{
	while (s->a)
	{
		*tmp = s->a->data;
		if (b->data > s->a->data)
		{
			*i += 1;
			if (b->data < s->a->next->data)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (issmall_exist(s->a, *tmp, b->data) == 1)
	{
		while (s->a)
		{
			if (s->a->data < *tmp && s->a->data > b->data)
				break ;
			*i += 1;
			s->a = s->a->next;
		}
	}
}

static int	fill_oper(t_stacks *s, t_list *b, t_oper *oper, int min)
{
	int	i;
	int	res;
	int	tmp;

	i = 0;
	tmp = 0;
	helper(s, b, &i, &tmp);
	if (s->a->half == -1)
		i = s->top_a - i;
	if (min == -1 || (i + b->index_to_edge) < min)
	{
		oper->dir_a = s->a->half;
		oper->dir_b = b->half;
		oper->index_a = i;
		oper->index_b = b->index_to_edge;
		res = i + b->index_to_edge;
	}
	else
		res = min;
	return (res);
}

void	instr_count(t_stacks *s, t_oper *oper)
{
	t_list	*beg_a;
	t_list	*beg_b;
	int		steps_min;

	steps_min = -1;
	beg_a = s->a;
	beg_b = s->b;
	while (s->b)
	{
		steps_min = fill_oper(s, s->b, oper, steps_min);
		s->a = beg_a;
		s->b = s->b->next;
	}
	s->b = beg_b;
}
