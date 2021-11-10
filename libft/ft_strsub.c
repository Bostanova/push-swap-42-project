#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	end;

	i = 0;
	if (!s || ((start + 1) == 0) || (len + 1) == 0)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len) + 1);
	if (!str)
		return (NULL);
	end = start + len;
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return ((char *)str);
}
