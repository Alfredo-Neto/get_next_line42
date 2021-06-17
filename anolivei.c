#include "get_next_line.h"

static int	gnl_end_line(char *s_line)
{
	int i;

	i = 0;
	if (s_line == 0)
		return (-1);
	while (s_line[i] != '\0')
	{
		if (s_line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	gnl_return_line(char **s_line, char **line)
{
	int		i;
	char	*tmp;

	i = gnl_end_line(*s_line);
	if (i >= 0)
	{
		*line = ft_substr(*s_line, 0, i);
		tmp = ft_substr(*s_line, i + 1, ft_strlen(*s_line));
		free(*s_line);
		*s_line = tmp;
		tmp = NULL;
		return (1);
	}
	else
		return (0);
}

int			get_next_line(int fd, char **line)
{
	char		buff[ARG_MAX];
	ssize_t		ret;
	static char	*s_l[OPEN_MAX];

	if (line == 0 || fd < 0 || BUFFER_SIZE == 0)
		return (-1);
	if (s_l[fd] != NULL)
	{
		if (gnl_return_line(&s_l[fd], line) == 1)
			return (1);
	}
	else
		s_l[fd] = ft_strdup("");
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		s_l[fd] = s_l[fd] == NULL ? ft_strdup(buff) : ft_strjoin(s_l[fd], buff);
		if (s_l[fd] == 0)
			return (-1);
		if (gnl_return_line(&s_l[fd], line) == 1)
			return (1);
	}
	*line = ret < 0 ? NULL : s_l[fd];
	s_l[fd] = NULL;
	return (ret);
}