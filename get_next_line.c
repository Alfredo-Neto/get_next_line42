/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:06:59 by ade-agui          #+#    #+#             */
/*   Updated: 2021/06/15 22:45:54 by ade-agui         ###   ########.fr       */
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
    while (line_read != '\0')
    {
        if(line_read[i] == '\n')
            return (i);
		i++;	
    }
	return (-1);
}

int get_next_line(int fd, char **line)
{
    int i;

    char end_of_line = readLine(line);
    i = 0;
    while (i < end_of_line)
    {
        // me de a proxima linha
        i++;
    }
   
}

int main(void)
{
    char **str = "Alfredo Jorge";
    printf("%s", &str);
    
    return (0);
}