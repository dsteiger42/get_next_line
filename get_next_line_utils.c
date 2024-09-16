/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:23:30 by dsteiger          #+#    #+#             */
/*   Updated: 2024/09/10 17:11:30 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
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
	j = 0;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
		dest[i++] = s2[j++];
	if (s2[j] == '\n')
		dest[i++] = s2[j];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

int	buffer_clear(char *buffer)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (flag == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			flag = 1;
		buffer[i++] = '\0';
	}
	return (flag);
}

char	*free_buf(char *buf)
{
	free(buf);
	return (NULL);
}
