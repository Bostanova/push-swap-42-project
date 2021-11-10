#include "push_swap.h"

static void	stack_index(t_list *b, int len)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = b;
	while (++i <= len / 2)
	{
		tmp->index_to_edge = i;
		tmp->half = 1;
		tmp = tmp->next;
	}
	if (len % 2 == 0)
		i--;
	while (--i > 0)
	{
		tmp->index_to_edge = i;
		tmp->half = -1;
		tmp = tmp->next;
	}
}

static int	to_begin(t_list *a, int min)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->data == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

static void	sort_begin(t_stacks *s)
{
	t_oper	*oper;

	oper = (t_oper *)malloc(sizeof(t_oper));
	if (!oper)
		exit(1);
	while (s->top_b != 0)
	{
		oper->dir_a = 0;
		oper->dir_b = 0;
		oper->index_a = -1;
		oper->index_b = -1;
		stack_index(s->a, s->top_a);
		stack_index(s->b, s->top_b);
		instr_count(s, oper);
		instr_begin(s, oper);
	}
	if ((to_begin(s->a, s->min)) > s->top_a / 2)
	{
		while (s->a->data != s->min)
			rev_rotate_a(&s->a, 1);
	}
	else
		while (s->a->data != s->min)
			rotate_a(&s->a, 1);
	free(oper);
}

void	common_sort(t_stacks *s)
{
	while (s->top_a > 2)
	{
		if (s->a->data != s->min && s->a->data != s->max)
		{
			push_b(s, 1);
			if (s->b->data > s->med)
				rotate_b(&s->b, 1);
		}
		else
			rotate_a(&s->a, 1);
	}
	if (s->a->data < s->a->next->data)
		swap_a(s->a, 1);
	push_a(s, 1);
	sort_begin(s);
}
