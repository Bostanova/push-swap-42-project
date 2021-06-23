#include "../includes/checker.h"

static void helper(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(cmd, "rra"))
		reverse_rotate(a);
	else if (!ft_strcmp(cmd, "rrb"))
		reverse_rotate(b);
	else if (!ft_strcmp(cmd, "rrr"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else if (!ft_strcmp(cmd, "pa"))
		push(a, b);
	else if (!ft_strcmp(cmd, "pb"))
		push(b, a);
	else
		ft_error();
}

void	call_cmd(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(cmd, "ra"))
		rotate(a);
	else if (!ft_strcmp(cmd, "rb"))
		rotate(b);
	else if (!ft_strcmp(cmd, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp(cmd, "sa"))
		swap(a);
	else if (!ft_strcmp(cmd, "sb"))
		swap(b);
	else if(!ft_strcmp(cmd, "ss"))
	{
		swap(a);
		swap(b);
	}
	else
		helper(cmd, a, b);
}
