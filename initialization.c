#include "push_swap.h"

void	init_array(t_stacks *s, t_input_array *ar)
{
	ar->len = 0;
	s->top_a = 0;
	s->top_b = 0;
	s->min = 0;
	s->max = 0;
	s->med = 0;
	s->a = NULL;
	s->b = NULL;
}

static t_list	*create_stack(const int *ar, int len)
{
	int		i;
	t_list	*a;
	t_list	*begin;

	i = 0;
	a = (t_list *)malloc(sizeof(t_list));
	if (!a)
		exit(1);
	begin = a;
	while (i < len)
	{
		if (i < len - 1)
		{
			a->next = (t_list *)malloc(sizeof(t_list));
			if (!a->next)
				exit(1);
		}
		a->data = ar[i];
		if (i == (len - 1))
			a->next = NULL;
		else
			a = a->next;
		i++;
	}
	return (begin);
}

void	init_stack(t_input_array *ar, t_stacks *s)
{
	s->a = create_stack(ar->a, ar->len);
	s->b = NULL;
}

void	free_stack(t_stacks *s)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < s->top_a)
	{
		tmp = s->a;
		s->a = s->a->next;
		free(tmp);
		i++;
	}
	i = 0;
	while (i < s->top_b)
	{
		tmp = s->b;
		s->b = s->b->next;
		free(tmp);
		i++;
	}
}
