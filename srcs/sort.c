#include "../includes/push_swap.h"

int	sorted(t_stack *stack)
{
	t_list *start;
	t_list *next;

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

void	sort_stack(t_stack *a, t_stack *b, int len)
{
	push_b(a, b);

	while (b->top < (len - 1))
	{
		
	}
}