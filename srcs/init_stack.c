#include "../includes/push_swap.h"
#include "../libft/libft.h"

static int	check_arg(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && ft_isdigit(str[1]))
		i++;
	if (str[0] == '+' && ft_isdigit(str[1]))
		i++;
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i])))
			return (1);
		i++;
	}
	return (0);
}

static void	check_dublicate(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;	
		while (j < i)
		{
			if (array[i] == array[j])
			{
				ft_putstr("Error. Please, enter numbers without dublicate\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static void	init_stack(t_stack *stack, int *array, int len)
{
	t_list	*new_node;
	int		i;

	stack->list = ft_lstnew(array[0]);
	stack->top = 0;
	i = 1;
	while (i < len)
	{
		new_node = ft_lstnew(array[i]);
		ft_lstadd_back(&stack->list, new_node);
		stack->top += 1;
		i += 1;
	}
	free(array);
}

void	create_stack(t_stack *stack, char **argv, int len)
{
	int		*array;
	int		i;

	array = (int *)malloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		if ((check_arg(argv[i + 1])) == 0)
			array[i] = ft_atoi(argv[i + 1]);
		else
		{
			ft_putstr("Error. Please, enter only numbers\n");
			exit(1);
		}
		i++;
	}
	check_dublicate(array, len);
	init_stack(stack, array, len);
}
