/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:23:30 by dsteiger          #+#    #+#             */
/*   Updated: 2024/08/23 19:13:25 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// conta o tamanho da string ate chegar a quebra de linha ('\n' incluido na contagem)
int	strlen_to_newline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	dest = malloc(strlen_to_newline(s1) + strlen_to_newline(s2) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && s2[j] != '\n')
	{
		dest[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
		dest[i + j++] = '\n';
	dest[i + j] = '\0';
	if (s1)
		free(s1);
	return (dest);
}

void	buffer_clear(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!buffer)
		return ;
	while (buffer[i] != '\n' && i < BUFFER_SIZE)   //apaga tudo antes da quebra de linha
	{
		buffer[i] = '\0';
		i++;
	}
	if (buffer[i] == '\n')   //apaga a quebra de linha
	{
		buffer[i] = '\0';
		i++;
		while (i < BUFFER_SIZE)   //apaga todos os 'i' dps da quebra de linha e copia pro 'j'
		{	
			buffer[j] = buffer[i];
			buffer[i] = '\0';
			i++;
			j++; 
		}
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s1;
	char	c1;

	s1 = (char *)str;
	c1 = (char )c;
	if (c == '\0')
		return (s1 + ft_strlen(s1));
	while (*s1)
	{
		if (*s1 == c1)
			return (s1);
		s1++;
	}
	return (NULL);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = str;
	while (i < n)
		mem[i++] = c;
	return (mem);
}
