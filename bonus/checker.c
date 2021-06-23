#include <stdio.h>
#include "../includes/checker.h"
#include "../libft/libft.h"

int	ft_error(void)
{
	ft_putstr("Error!");
	exit(1);
}

t_stack *stack_malloc(int len)
{
	t_stack *a;
	int		i;

	a = (t_stack *)malloc(sizeof(t_stack));
	a->data = (int *)malloc(len * sizeof(int));
	if (!a || !a->data)
		ft_error();
	i = 0;
	while( i < len)
	{
		a->data[i] = 0;
		i++;
	}
	return(a);
}

int	check_a(t_stack *a, int top)
{
	int i;

	if (a->top != top)
		return (1);
	i = 0;
	while (i < top)
	{
		if (a->data[i] > a->data[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*cmd;
	

	if (argc > 2)
	{
		a = stack_malloc(argc-1);
		b = stack_malloc(argc-1);
		a->top = argc - 2;
		b->top = -1;
		create_a(a, (argc - 1), argv);

		for (int i = 0; i < argc - 1; i++)
			printf ("%d	", a->data[i]);
		
		while (get_next_line(0, &cmd) > 0)
		{
			call_cmd(cmd, a, b);
			free(cmd);
		}
		if (b->top == -1 && !check_a(a, argc - 2))
			ft_putstr("OK\n");
	}
}
