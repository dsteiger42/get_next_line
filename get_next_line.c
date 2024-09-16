/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:12:42 by dsteiger          #+#    #+#             */
/*   Updated: 2024/09/16 16:24:19 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*dest;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dest = malloc(1 * sizeof(char));
	if (!dest)
		return (NULL);
	dest[0] = '\0';
	dest = ft_strjoin(dest, buf);
	if (buffer_clear(buf) == 1)
		return (dest);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0 && (!*dest))
		return (free_buf(dest));
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		dest = ft_strjoin(dest, buf);
		if (buffer_clear(buf) == 1)
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	return (dest);
}

// int	main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	int *line;
// 	if (fd == -1)
// 		return (1);
// 	while (line = get_next_line(fd))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
