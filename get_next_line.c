/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:06:59 by ade-agui          #+#    #+#             */
/*   Updated: 2021/06/20 05:01:17 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int    find_line_break(char *s_line)
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

int output(char **save, char **line, int ret)
{
	int i;

	i = find_line_break(*save);
	if (ret < 0)
		*line = NULL;
	else
		*line = ft_substr(*save, 0, i); // olamundo\nolajorge // save = olamundo\no
	save = NULL;
	return (ret);
}

int get_next_line(int fd, char **line)
{
	char *buffer;
	char *tmp;
	static char *save;
	ssize_t ret;

	// verify_save();
	buffer = malloc(BUFFER_SIZE + 1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (save == NULL)
			save = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(save, buffer); // olamundo\nolajorge // save = olamundo\no
			free(save);
			save = tmp;
		}
		if (ft_strchr(buffer, '\n'))
			break;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (output(&save, line, ret));
}

int main(void)
{
	char *linha;
	int fd;

	fd = open("/home/alfredobraule/gnl_test.txt", O_RDONLY);
	while (get_next_line(fd, &linha))
	{
		printf("%s", linha);
		printf("\n");
		free(linha);
	}
}