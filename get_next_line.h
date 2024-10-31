/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrey <marrey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:08:55 by marrey            #+#    #+#             */
/*   Updated: 2024/10/30 18:00:29 by marrey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int	ft_checkfornewline(char *str);
char	*get_next_line(int fd);
char	*ft_line_to_return(char    **str);
char	*ft_strdup(const char *str, size_t n);
char	*ft_strjoin(char *str, char *str2add);
void	ft_putstr(char  *str);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);
void free_memory(char **buffer);

#endif
