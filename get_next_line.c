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

char *get_next_line(int fd) {
    static char buf[BUFFER_SIZE + 1] = {0};
    char *dest = NULL;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    dest = malloc(1);
    if (!dest)
        return NULL;
    dest[0] = '\0';
    dest = ft_strjoin(dest, buf);   // joins the leftover rom previous reads
    buffer_clear(buf);
    while (!ft_strchr(dest, '\n'))     // strchr finds the \n in a str. In this case, while its not == \n
                                        // trocar pra *dest != \n pq nao posso usar strchr. dest++.
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buf[bytes_read] = '\0'; // null terminating the string in 'buf'
        dest = ft_strjoin(dest, buf);
        buffer_clear(buf);
    }
    if (dest[0] == '\0') {
        free(dest);
        return NULL;
    }
    return dest;
}
