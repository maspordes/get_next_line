/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrey <marrey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:04:15 by marrey            #+#    #+#             */
/*   Updated: 2024/10/14 20:49:51 by marrey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	ssize_t	bytes_read; //we need to count how many bytes are being read
	static char	*static_buffer[]; //where we will store and append the buffers
	char	buffer[BUFFER_SIZE + 1];
	
	bytes_read = read(int fd, void *buffer, size_t BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer); 
	}
	else if (bytes_read == 0)
		return (0);
	else if (bytes_read < 0)
	{
		ft_putstr("there was an error reading the file");
		return(-1);
	}

	if (ft_checkfornewline(static_buffer) != 0)
		return(ft_line_to_return(static_buffer));
	ft_putstr("no more lines to read");
	return (-1);
	// else - keep reading until we find a new line char
	// (ensure to return the line even if we dont find a "\n", when file is finished)
}

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h" 

int main(void)
{
  int    fd;
  char  *next_line;
  int  count;

  count = 0;
  fd = open("example.txt", O_RDONLY);
  while (1)
  {
    next_line = get_next_line(fd);
    if (next_line == NULL)
      break ;
    count++;
    printf("[%d]:%s\n", count, next_line);
    next_line = NULL;
  }
  close(fd);
  return (0);
}