#include "libft.h"

/*  Converts the initial portion of the string pointed to by str 
	to int representation                                         */

static void	check_max(ssize_t nbr)
{
	if (nbr < -2147483648 || nbr > 2147483647)
		ft_error();
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	ssize_t	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	check_max(res * sign);
	return ((int)(res * sign));
}
