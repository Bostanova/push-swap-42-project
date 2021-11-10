#include "push_swap.h"

static int	exist_nbr(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_isspace(s[i]))
			return (1);
	}
	return (0);
}

static void	isnumber(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			return ;
		i++;
	}
	ft_error();
}

static void	check_sign(const char *s)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]))
			nbr++;
		else if (s[i] == ' ' || s[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0;
			sign = 0;
		}
		else if (((s[i] == '+' || s[i] == '-')
				&& (sign == 0 && nbr == 0)) && (s[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (i < argc)
	{
		if (exist_nbr(argv[i]))
		{
			isnumber(argv[i]);
			check_sign(argv[i]);
			res = 1;
		}
		i++;
	}
	return (res);
}

void	check_dupl(t_input_array *ar, t_stacks *s)
{
	int	*tmp;
	int	i;

	tmp = (int *)malloc(sizeof(int) * (ar->len));
	if (!tmp)
		exit(1);
	tmp = ft_intcpy(tmp, ar->a, ar->len);
	quick_sort(tmp, 0, ar->len - 1);
	i = 0;
	while (i < ar->len - 1)
	{
		if (tmp[i] == tmp[i + 1])
			ft_error();
		i++;
	}
	s->top_a = ar->len;
	s->top_b = 0;
	s->min = tmp[0];
	s->max = tmp[ar->len - 1];
	s->med = tmp[ar->len / 2];
	free(tmp);
}
