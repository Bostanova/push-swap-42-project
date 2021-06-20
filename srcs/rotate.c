#include "../includes/push_swap.h"

static t_stack	*rotate(t_stack *stack)
{
	t_list	*tmp;
	t_list	*head;

	head = stack->list;
	tmp = stack->list;
	stack->list = stack->list->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = head;
	head->next = NULL;
	stack->tail = head->content;
	return (stack);
}

void	rotate_a(t_stack *stack)
{
	if (stack->top > 0)
	{
		stack = rotate(stack);
		ft_putstr("ra\n");
	}
}

void	rotate_b(t_stack *stack)
{
	if (stack->top > 0)
	{
		stack = rotate(stack);
		ft_putstr("rb\n");
	}
}

void	rotate_both(t_stack *stack1, t_stack *stack2)
{
	if (stack1->top > 0 && stack2 > 0)
	{
		stack1 = rotate(stack1);
		stack2 = rotate(stack2);
		ft_putstr("rr\n");
	}
}
