#include "push_swap.h"

void	rev_rotate_a(t_list **a, int i)
{
	t_list		*begin;
	t_list		*end;
	t_list		*tmp;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	begin = *a;
	tmp = *a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	end = tmp->next;
	tmp->next = NULL;
	end->next = begin;
	*a = end;
	if (i == 1)
		ft_putstr("rra\n");
}

void	rev_rotate_b(t_list **b, int i)
{
	t_list		*begin;
	t_list		*end;
	t_list		*tmp;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	begin = *b;
	tmp = *b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	end = tmp->next;
	tmp->next = NULL;
	end->next = begin;
	*b = end;
	if (i == 1)
		ft_putstr("rrb\n");
}

void	rev_rotate_ab(t_stacks *s, int i)
{
	rev_rotate_a(&s->a, 0);
	rev_rotate_b(&s->b, 0);
	if (i == 1)
		ft_putstr("rrr\n");
}
