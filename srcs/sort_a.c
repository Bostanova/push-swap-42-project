#include "../includes/push_swap.h"

static int	help_two(t_stack *a, t_stack *b)
{
	if (a->top > -1 && a->list->content < a->list->next->content
		&& a->list->content < a->tail)
	{
		push_b(a, b);
		return (1);
	}
	return (0);
}

static int	help_one(t_stack *a, t_stack *b)
{
	if (a->top > 0 && a->list->content > a->list->next->content)
	{
		if (b->top > 0 && b->list->content < b->list->next->content)
		{
			swap_both(a, b);
			return (1);
		}
		else
		{
			swap_a(a);
			return (1);
		}
	}
	else if (b->top > 0 && b->list->content < b->list->next->content)
	{
		swap_b(b);
		return (1);
	}
	else
		return (help_two(a, b));
	return (0);
}

int	        sort_a(t_stack *a, t_stack *b)
{
	while (sorted(a))
	{
		if (a->top > 0 && a->list->content > a->tail)
		{
			if (b->top > 0 && b->list->content < b->tail)
			{
				rev_rotate_both(a, b);
				return (1);
			}
			else
			{
				rev_rotate_a(a);
				return (1);
			}
		}
		else if (b->top > 0 && b->list->content < b->tail)
		{
			rotate_b(b);
			return (1);
		}
		else
			return (help_one(a, b));
	}
	return (0);
}
