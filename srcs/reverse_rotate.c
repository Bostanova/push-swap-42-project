#include "../includes/push_swap.h"

static t_stack	*rev_rotate(t_stack *stack)
{
	t_list	*tmp;
	t_list	*prev;
	
	if (stack->top < 1)
		return (stack);
	prev = stack->list;
	tmp = stack->list->next;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		prev = prev->next;
	}
	tmp->next = stack->list;
	prev->next = NULL;
	stack->list = tmp;
	return(stack);
}

void	rev_rotate_a(t_stack *stack)
{
	if (stack->top > 0)
	{
		stack = rev_rotate(stack);
		ft_putstr("rra\n");
	}
}

void	rev_rotate_b(t_stack *stack)
{
	if (stack->top > 0)
	{
		stack = rev_rotate(stack);
		ft_putstr("rrb\n");
	}
}

void	rev_rotate_both(t_stack *stack1, t_stack *stack2)
{
	if (stack1->top > 0 && stack2 > 0)
	{
		stack1 = rev_rotate(stack1);
		stack2 = rev_rotate(stack2);
		ft_putstr("rrr\n");
	}
}
