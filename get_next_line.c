/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:06:59 by ade-agui          #+#    #+#             */
/*   Updated: 2021/06/25 15:26:43 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_line_break(char *s_line)
{
	int	i;

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

static int check_ret(char **save, char **line, ssize_t ret)
{
	if (ret < 0)
	{
		free(*line);
		*line = NULL;
        free(*line);
	}
	else if (*save == NULL)
		*line = ft_strdup("");
	else
		*line = ft_strdup(*save);
	free(*save);
	*save = NULL;
	return (ret);
}

static int	return_line(char **save, char **line, ssize_t ret)
{
	int		i;
	char	*tmp;

	i = find_line_break(*save);
	if (i >= 0)
	{
		*line = ft_substr(*save, 0, i);
		tmp = ft_substr(*save, i + 1, ft_strlen(*save));
		free(*save);
		*save = tmp;
		return (1);
	}
	else
		return (check_ret(save, line, ret));
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	char		*tmp;
	static char	*save;
	ssize_t		ret;

	buffer = malloc(BUFFER_SIZE + 1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (save == NULL)
			save = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(save, buffer);
			free(save);
			save = tmp;
		}
		if (ft_strchr(save, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (return_line(&save, line, ret));
}