#include "../includes/push_swap.h"

static t_stack	*swap(t_stack *stack)
{
	t_list	*tmp;
	
	tmp = stack->list->next;
	stack->list->next = tmp->next;
	tmp->next = stack->list;
	stack->list = tmp;
	return(stack);
}

void	swap_a(t_stack *stack)
{
	if (stack->top > 0)
	{
		stack = swap(stack);
		ft_putstr("sa\n");
	}
}

void	swap_b(t_stack *stack)
{
	if (stack->top > 0)
	{
		stack = swap(stack);
		ft_putstr("sb\n");
	}
}

void	swap_both(t_stack *stack1, t_stack *stack2)
{
	if (stack1->top > 0 && stack2 > 0)
	{
		stack1 = swap(stack1);
		stack2 = swap(stack2);
		ft_putstr("ss\n");
	}
}
