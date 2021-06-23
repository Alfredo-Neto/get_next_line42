/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:11:46 by ade-agui          #+#    #+#             */
/*   Updated: 2021/06/23 02:03:22 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + 1;
	s2 = (char *)malloc(size);
	if (s2 == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		((unsigned char *)s2)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;
	size_t	i;
	size_t	j;

	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	join = (char *)malloc(len);
	if (!s1 || !s2 || join == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (c % 256))
		s++;
	if (*s == '\0' && (c % 256) != '\0')
		return (0);
	else
		return ((char *)s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	substr_len;
	char	*substr;

	i = 0;
	if (s == 0)
		return (0);
	substr_len = ft_strlen(s);
	if (substr_len < len)
		substr = (char *)malloc((substr_len + 1));
	else
		substr = (char *)malloc((len + 1));
	if (substr == 0)
		return (0);
	while (i < len && (start + i) < substr_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
