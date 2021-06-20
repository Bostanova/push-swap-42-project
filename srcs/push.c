#include "../includes/push_swap.h"

static void	push(t_stack *a, t_stack *b)
{
	t_list	*new;
	t_list	*tmp;

	new = ft_lstnew(b->list->content);
	ft_lstadd_front(&a->list, new);
	a->top += 1;
	if (a->top == 0)
		a->tail = a->list->content;
	tmp = b->list->next;
	free(b->list);
	b->list = tmp;
	b->top -= 1;
	if (b->top == -1)
		b->tail = INT32_MAX;
}

void	push_a(t_stack *a, t_stack *b)
{
	if (b->top >= 0)
	{
		push(a, b);
		ft_putstr("pa\n");
	}
}

void	push_b(t_stack *a, t_stack *b)
{
	if (a->top >= 0)
	{
		push(b, a);
		ft_putstr("pb\n");
	}
}
