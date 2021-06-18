#include "libft.h"

/*  Converts the initial portion of the string pointed to by str 
	to int representation                                         */

static void	max_min_int(long long nbr)
{
	if (nbr > 2147483647)
		ft_putstr("Error. Number bigger than MAX_INT\n");
	else
		ft_putstr("Error. Number less than MIN_INT\n");
	exit(1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

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
	if (res * sign > 2147483647 || res * sign < -2147483648)
		max_min_int(res * sign);
	return ((int)(res * sign));
}
