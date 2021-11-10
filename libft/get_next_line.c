#include "libft.h"

static int	finish(char **str, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_strsub(*str, 0, len);
		tmp = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = NULL;
		*str = tmp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	returns(char **str, char **line, int val, int fd)
{
	if (val < 0)
		return (-1);
	else if (val == 0 && str[fd] == NULL)
		return (0);
	else
		return (finish(&str[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[20000];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			reader;

	if (fd < 0 || line == NULL)
		return (-1);
	reader = read(fd, buff, BUFFER_SIZE);
	while (reader > 0)
	{
		buff[reader] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
		reader = read(fd, buff, BUFFER_SIZE);
	}
	return (returns(str, line, reader, fd));
}
