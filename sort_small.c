#include "push_swap.h"

int	find_max(t_list *s)
{
	int	max;

	max = s->data;
	while (s)
	{
		if (s->data > max)
			max = s->data;
		s = s->next;
	}
	return (max);
}

void	sort_three(t_stacks *s)
{
	int	max;

	max = find_max(s->a);
	if (s->top_a == 1)
		return ;
	else if (s->top_a == 2)
	{
		if (s->a->data > s->a->next->data)
			swap_a(s->a, 1);
		return ;
	}
	else if (s->top_a == 3)
	{
		if (s->a->data == max)
			rotate_a(&s->a, 1);
		if (s->a->next->data == max)
			rev_rotate_a(&s->a, 1);
		if (s->a->data > s->a->next->data)
			swap_a(s->a, 1);
	}
}

void	sort_five(t_stacks *s)
{
	while (s->top_b < 2)
	{
		if (s->a->data == s->min || s->a->data == s->max)
			push_b(s, 1);
		else
			rotate_a(&s->a, 1);
	}
	sort_three(s);
	push_a(s, 1);
	push_a(s, 1);
	if (s->a->data == s->max)
	{
		rotate_a(&s->a, 1);
	}
	else
	{
		swap_a(s->a, 1);
		rotate_a(&s->a, 1);
	}
}
