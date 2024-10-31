/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrey <marrey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:04:15 by marrey            #+#    #+#             */
/*   Updated: 2024/10/31 16:35:15 by marrey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	bytes_read;
	static char	*static_buffer = NULL;
	char	buffer[BUFFER_SIZE + 1];
	
	if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	
	while (1)
	{	
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0) //Handling Error while reading
		{
			free_memory(&static_buffer);
			return (NULL);
		}
		if (bytes_read == 0) //handling EOF
		{
			if (static_buffer && *static_buffer) //Return content if there
				return (ft_line_to_return(static_buffer));
			free_memory(&static_buffer);
			return (NULL);
		}		
		buffer[bytes_read] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	    if (!static_buffer)
            return (NULL);
		if (ft_checkfornewline(static_buffer) != 0 ) //Check if a newline is there
			return(ft_line_to_return(static_buffer));
	}
}

char *ft_line_to_return(char    *str)
{
    int count;
    int len;
    char    *str_to_return;
    
	if (!str || !*str)
		return (NULL);
    len = ft_strlen(str);
	count = ft_checkfornewline(str);
	
    if (count == -1)
		count = len;

	str_to_return = ft_strdup(str, count);
	if (!str_to_return)
		return (NULL);
	if (count == len)
		str[0] = '\0';
	else 
		(ft_memmove(str, str + count + 1, len - count));
    return(str_to_return);
}


int ft_checkfornewline(char *str)
{
    int count;

    count = 0;
    while (str && *str)
    {
        if (*str == '\n')
            return (count);
        str++;
        count++;
    }
    return (-1);
}

#include "get_next_line.h"
#include <stdio.h> // Needed for printf

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
