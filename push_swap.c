#include "push_swap.h"

static int	check_sorting(t_input_array *ar)
{
	int	i;

	i = 0;
	while (i < (ar->len - 1))
	{
		if (ar->a[i] > ar->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static void	sorting(t_stacks *s)
{
	if (s->top_a <= 3)
		sort_three(s);
	else if (s->top_a <= 5)
		sort_five(s);
	else
		common_sort(s);
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
		if (check_sorting(ar))
		{
			init_stack(ar, s);
			sorting(s);
			free_stack(s);
		}
	}
	free(ar);
	free(s);
	return (0);
}
