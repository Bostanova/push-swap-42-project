#include "push_swap.h"

static void	helper_recur(t_input_array *ar, int *tmp, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		ar->a[ar->len + i] = tmp[i];
	ar->len += len;
	free(tmp);
}

void	fill_array(int argc, char **argv, t_input_array *ar)
{
	int		i;
	int		j;
	int		*tmp;
	char	**buf;
	int		len;

	i = 1;
	while (i < argc)
	{
		j = -1;
		len = ft_countword(argv[i]);
		buf = ft_split(argv[i], len);
		tmp = (int *)malloc(sizeof(int) * (len));
		if (!tmp)
			exit(1);
		while (++j < len)
		{
			tmp[j] = ft_atoi(buf[j]);
			free(buf[j]);
		}
		free(buf);
		helper_recur(ar, tmp, len);
		i++;
	}
}
