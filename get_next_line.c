/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:06:59 by ade-agui          #+#    #+#             */
/*   Updated: 2021/06/19 21:12:02 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int return_previous_line(char **save, char **line, int ret)
{
	if (ret < 0)
		*line =  NULL;
	else
		*line = ft_strdup(*save);
	save = NULL;
    return (ret);
}

int get_next_line(int fd, char **line)
{
	char *buffer;
	char *tmp;
	static char *save;
	ssize_t ret;

	buffer = malloc(BUFFER_SIZE + 1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (save == NULL)
			save = ft_strdup(buffer);
		else 
		{
			tmp = ft_strjoin(save, buffer); // olamundo\nolajorge
			free(save);
			save = tmp;
		}
		if (ft_strchr(buffer, '\n'))
			break;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (return_previous_line(&save, line, ret));
}

int main()
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