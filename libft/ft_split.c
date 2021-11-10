#include "libft.h"

int	ft_countword(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			count++;
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void	fill(char const *s, char **ar)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				ar[i][j++] = *s++;
			ar[i++][j] = '\0';
		}
		j = 0;
		if (*s != '\0')
			s++;
	}
}

static int	memory_al(char const *s, char **ar)
{
	int	len;
	int	i;

	i = 0;
	while (*s)
	{
		len = 0;
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
			{
				s++;
				len++;
			}
			ar[i] = ((char *)malloc((len + 1) * sizeof(char)));
			if (!ar[i++])
				return (i);
		}
		else
			s++;
	}
	return (0);
}

char	**ft_split(char const *s, int len)
{
	char	**ar;
	int		res;

	if (!s)
		return (NULL);
	ar = (char **)malloc(sizeof(char *) * (len + 1));
	if (!ar)
		exit(1);
	ar[len] = NULL;
	res = memory_al(s, ar);
	if (res == 0)
		fill(s, ar);
	else
	{
		while (res != 0)
		{
			free(ar[res]);
			ar[res--] = NULL;
		}
		free(ar);
	}
	return ((char **)ar);
}
