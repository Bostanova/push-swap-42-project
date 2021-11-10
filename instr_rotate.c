#include "push_swap.h"

void	instr_begin(t_stacks *s, t_oper *oper)
{
	while (oper->index_a > 0)
	{
		if (oper->dir_a == 1)
			rotate_a(&s->a, 1);
		else
			rev_rotate_a(&s->a, 1);
		oper->index_a--;
	}
	while (oper->index_b > 0)
	{
		if (oper->dir_b == 1)
			rotate_b(&s->b, 1);
		else
			rev_rotate_b(&s->b, 1);
		oper->index_b--;
	}
	push_a(s, 1);
}

void	rotate_a(t_list **a, int i)
{
	t_list	*begin;
	t_list	*end;
	t_list	*tmp;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	begin = (*a)->next;
	end = *a;
	while (end->next != NULL)
		end = end->next;
	tmp->next = NULL;
	end->next = tmp;
	*a = begin;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **b, int i)
{
	t_list	*begin;
	t_list	*end;
	t_list	*tmp;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	tmp = *b;
	begin = (*b)->next;
	end = *b;
	while (end->next != NULL)
		end = end->next;
	tmp->next = NULL;
	end->next = tmp;
	*b = begin;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_stacks *s, int i)
{
	if (i == 1)
		write(1, "rr\n", 3);
	rotate_a(&s->a, 0);
	rotate_b(&s->b, 0);
}
