#include "../includes/push_swap.h"

int	sorted(t_stack *stack)
{
	t_list	*start;
	t_list	*next;

	start = stack->list;
	next = start->next;
	while (next != NULL)
	{
		if (start->content > next->content)
			return (1);
		next = next->next;
		start = start->next;
	}
	return (0);
}

static int	sort_b(t_stack *a, t_stack *b)
{
	while (b->top != -1)
	{
		if (sorted(a))
			sort_a(a, b);
		if (b->top > 0 && (b->list->content < b->list->next->content
				|| b->list->content < b->tail))
		{
			if (b->list->next->content < b->tail)
			{
				rotate_b(b);
				return (1);
			}
			else if (b->list->content < b->list->next->content)
			{
				swap_b(b);
				return (1);
			}
		}
		if (b->top > -1)
			push_a(a, b);
		sort_a(a, b);
	}
	return (0);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	iter;

	iter = 1;
	while (iter)
		iter = sort_a(a, b);
	iter = 1;
	while (iter)
		iter = sort_b(a, b);
}
