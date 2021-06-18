/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:06:59 by ade-agui          #+#    #+#             */
/*   Updated: 2021/06/17 23:47:18 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int readLine(char *line_read)
{
	int i;

	i = 0;
	if (line_read == 0)
		return (-1);
	while (line_read[i] != '\0')
	{
		if (line_read[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
/*
EXPLICACAO GERAL DO GET NEXT LINE:

O get next line lê uma linha inteira do arquivo indexado por fd, e faz o ponterio line 
apontar para uma string allocada com os conteudos dessa linha sem a quebra de linha '\n'.

Nao temos que passar nada allocado para o get_next_line, 
apenas passar o endereco de um ponteiro que vai apontar para a string allocada.
Precisamos poder dar free() nessa string allocada depois da chamada.

A gente vai ler o arquivo com a funcao read(), que avanca a sua posicao 
no file descriptor automaticamente.

A gente precisa usar um array estatico como buffer do read para poder 
acessar o que foi lido pelo read nas chamadas anteriores.

Precisamos tratar as seguintes situacoes:
  1. Se o buffer lido nao tem '\n', concatenamos com o buffer anterior e chamamos read novamente.
  2. Se o buffer lido tem '\n', concatenamos com o buffer anterior ate o '\n'.
  3. Se chegamos no final do arquivo (read() = 0), concatenamos com o buffer anterior.
  4. Finalmente temos que apontar o ponteiro line passado para uma string 
  allocada que contenha a linha inteira sem o '\n'. Depois liberamos a memoria allocada
  nas strings intermediarias e retornamos 1 ou 0 para '\n' ou final do arquivo respectivamente.
  5. Se os parametros tem algum problema (BUFFER_SIZE <= 0), ou em alguma 
  dessas operacaoes nao conseguimos allocar memoria, liberamos toda a memoria allocada e retornamos -1.
*/
int get_next_line(int fd, char **line)
{
	static char *buffer;
	char *tmp;
	char *cat;
	ssize_t ret;

	if (line == 0 || BUFFER_SIZE == 0)
		return (0);
	// *line  = ft_strdup("");
	tmp = malloc(BUFFER_SIZE + 1);
	ret = read(fd, tmp, BUFFER_SIZE);
	while (ret > 0)
	{
		tmp[ret] = '\0';
		if (buffer == NULL)
			buffer = ft_strdup(tmp);
		else 
		{
			cat = ft_strjoin(buffer, tmp);
		}	
		if (ft_strchr(buffer, '\n'))
			break;
		ret = read(fd, tmp, BUFFER_SIZE);
	}
	// free(buffer);
	if (buffer != 0)
		return (-1);
}

int main()
{
	char *linha;
	int fd;
	
	fd = open("./caminho/do/arquivo", O_RDONLY);
	get_next_line(0, &linha);
	printf("%s", linha);
	free(linha);
}
