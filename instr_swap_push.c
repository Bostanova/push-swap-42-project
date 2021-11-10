#include "push_swap.h"

void	swap_a(t_list *a, int i)
{
	int		tmp;

	if (a == NULL || a->next == NULL)
		return ;
	tmp = a->data;
	a->data = a->next->data;
	a->next->data = tmp;
	if (i == 1)
		ft_putstr("sa\n");
}

void	swap_b(t_list *b, int i)
{
	int		tmp;

	if (b == NULL || b->next == NULL)
		return ;
	tmp = b->data;
	b->data = b->next->data;
	b->next->data = tmp;
	if (i == 1)
		ft_putstr("sb\n");
}

void	swap_ab(t_stacks *s, int i)
{
	swap_a(s->a, 0);
	swap_b(s->b, 0);
	if (i == 1)
		ft_putstr("ss\n");
}

void	push_a(t_stacks *s, int i)
{
	t_list	*tmp;

	if (s->b == NULL)
		return ;
	s->top_a += 1;
	s->top_b -= 1;
	tmp = s->b;
	s->b = s->b->next;
	tmp->next = s->a;
	s->a = tmp;
	if (i == 1)
		ft_putstr("pa\n");
}

void	push_b(t_stacks *s, int i)
{
	t_list	*tmp;

	if (s->a == NULL)
		return ;
	s->top_a -= 1;
	s->top_b += 1;
	tmp = s->a;
	s->a = s->a->next;
	tmp->next = s->b;
	s->b = tmp;
	if (i == 1)
		ft_putstr("pb\n");
}
