/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:12:42 by dsteiger          #+#    #+#             */
/*   Updated: 2024/06/21 13:39:32 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf [BUFFER_SIZE + 1];
	char i;
	char *dest;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dest = malloc(sizeof(char) * 1);
	if (!dest)
		return (NULL);
	dest[0] = '\0';			// inicializar a str
	ft_strjoin(dest, buf);	//qd tiver \n antes de ler o buffer todo, os caracteres que faltam ler, ficam armazenados no static buffer
	if (buffer_clear(buf) == '\n')
		return (dest);
	
	
	
	
	read(fd, buf, BUFFER_SIZE);



	
}

