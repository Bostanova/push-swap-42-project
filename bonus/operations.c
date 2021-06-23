#include "../includes/checker.h"

void	rotate(t_stack *stack)
{
	int tmp;
	int	i;

	tmp = stack->data[0];
	if (stack->top >= 1)
	{
		if (stack->top == 1)
		{
			stack->data[0] = stack->data[1];
			stack->data[1] = tmp;
		}
		else
		{
			i = 0;
			while(i < stack->top)
			{
				stack->data[i] = stack->data[i + 1];
				i++;
			}
			stack->data[stack->top] = tmp;
		}
	}
}

void	reverse_rotate(t_stack *stack)
{
	int tmp;
	int	i;

	tmp = stack->data[stack->top];
	if (stack->top >= 1)
	{
		if (stack->top == 1)
		{
			stack->data[1] = stack->data[0];
			stack->data[0] = tmp;
		}
		else
		{
			i = stack->top;
			while(i > -1)
			{
				stack->data[i] = stack->data[i - 1];
				i--;
			}
			stack->data[0] = tmp;
		}
	}
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->top >= 1)
	{
		tmp = stack->data[0];
		stack->data[0] = stack->data[1];
		stack->data[1] = tmp;
	}
}

void	push(t_stack *a, t_stack *b)
{
	int	i;

	i = a->top;
	if (b->top >= 0)
	{
		while (i >= 0)
		{
			a->data[i + 1] = a->data[i];
			i--;
		}
		a->data[0] = b->data[0];
		a->top += 1;
		i = 0;
		while (i < b->top)
		{
			b->data[i] = b->data[i + 1];
			i++;
		}
		b->top -= 1;
	}
}