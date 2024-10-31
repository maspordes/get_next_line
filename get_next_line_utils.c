/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrey <marrey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:09:03 by marrey            #+#    #+#             */
/*   Updated: 2024/10/31 16:30:31 by marrey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//code to return a line excepts the characters after the new line character
#include "get_next_line.h"

void	free_memory(char **buffer) //function to free dinamically allocated memory
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

char	*ft_strdup(const char *str, size_t n)
{
	char	*new_str;
	
	new_str = (char *)malloc((n + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str, n + 1);
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	i;

	count = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (count);
}

char    *ft_strjoin(char *str, char *str2add)
{
    char    *str2return;
	size_t	len1;
	size_t	len2;
	
    if (!str)
		return (ft_strdup(str2add, ft_strlen(str2add)));
	if (!str && !str2add)
    	return (ft_strdup("", 0));
	len1 = ft_strlen(str);
	len2 = ft_strlen(str2add);
	str2return = (char *)malloc(sizeof(char) * (len1 + len2 +1));
	if (!str2return)
		return (NULL);
	ft_strlcpy(str2return, str, len1 + 1);
	ft_strlcpy(str2return + len1, str2add, len2 + 1);
	free_memory(&str);
    return (str2return);
}

void    ft_putstr(char  *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

//calloc -- standard memory allocation function that stands for contiguous allocation
//          it allocates memory for an array of elements, initializes all bits to zero
//          and returns a pointer to the allocated memory.
void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
    size_t  len;

    len = count * size;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	while (len--)
        *ptr++ = 0;
	return (ptr);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d == s || len == 0)
		return (dst);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*(--d) = *(--s);
	}
	return (dst);
}
