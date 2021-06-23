#include "../includes/checker.h"

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

void	create_a(t_stack *a, int len, char **argv)
{
	int		i;

	i = 0;
	while(i < len)
	{
		if ((check_arg(argv[i + 1])) == 0)
			a->data[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}