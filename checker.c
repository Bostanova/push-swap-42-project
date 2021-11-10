#include "push_swap.h"

static int	is_sorted(t_stacks *s, t_input_array *ar)
{
	int		*tmp;
	t_list	*begin;
	int		i;

	begin = s->a;
	tmp = (int *)malloc(sizeof(int) * (ar->len));
	if (!tmp)
		exit(1);
	tmp = ft_intcpy(tmp, ar->a, ar->len);
	quick_sort(tmp, 0, ar->len - 1);
	i = 0;
	while (i < ar->len)
	{
		if (tmp[i] != s->a->data)
			return (0);
		i++;
		s->a = s->a->next;
	}
	s->a = begin;
	free(tmp);
	return (1);
}

static void	instr_exec(char *line, t_stacks *s)
{
	if (!ft_strcmp(line, "pa"))
		push_a(s, 0);
	else if (!ft_strcmp(line, "pb"))
		push_b(s, 0);
	else if (!ft_strcmp(line, "sa"))
		swap_a(s->a, 0);
	else if (!ft_strcmp(line, "sb"))
		swap_b(s->b, 0);
	else if (!ft_strcmp(line, "ss"))
		swap_ab(s, 0);
	else if (!ft_strcmp(line, "ra"))
		rotate_a(&s->a, 0);
	else if (!ft_strcmp(line, "rb"))
		rotate_b(&s->b, 0);
	else if (!ft_strcmp(line, "rr"))
		rotate_ab(s, 0);
	else if (!ft_strcmp(line, "rra"))
		rev_rotate_a(&s->a, 0);
	else if (!ft_strcmp(line, "rrb"))
		rev_rotate_b(&s->b, 0);
	else if (!ft_strcmp(line, "rrr"))
		rev_rotate_ab(s, 0);
	else
		ft_error();
}

static void	get_input(t_stacks *s)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		instr_exec(line, s);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_input_array	*ar;
	t_stacks		*s;

	if (argc < 2)
		exit(1);
	ar = (t_input_array *)malloc(sizeof(t_input_array));
	s = (t_stacks *)malloc(sizeof(t_stacks));
	if (!ar || !s)
		exit(1);
	init_array(s, ar);
	if (check_args(argc, argv))
	{
		fill_array(argc, argv, ar);
		check_dupl(ar, s);
		init_stack(ar, s);
		get_input(s);
		if ((is_sorted(s, ar)) && s->top_b == 0)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	free_stack(s);
	free(ar);
	free(s);
	return (0);
}
