/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:06:59 by ade-agui          #+#    #+#             */
/*   Updated: 2021/06/17 02:28:54 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int readLine(char *line_read)
{
    int i ;

    i = 0;
	if (line_read == 0)
		return (-1);
    while (line_read[i] != '\0')
    {
        if(line_read[i] == '\n')
            return (i);
		i++;	
    }
	return (-1);
}

int    get_next_line(int fd, char **line)
{
	static char	*buff[ARG_MAX];
	char		*tmp[OPEN_MAX];
	ssize_t		ret;
   
	if (line == 0 || BUFFER_SIZE == 0)
		return (-1);
	// *line  = ft_strdup("");
	tmp = malloc(BUFFER_SIZE + 1);
	if (line && BUFFER_SIZE > 0)
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		while (ret > 0)
		{
			tmp[ret] = '\0';
			if (ret == NULL)
				buff = ft_strdup(tmp);
		}
	}
}
   
int main(void)
{
    char **str = "Alfredo Jorge";
    printf("%s", &str);
    
    return (0);
}
