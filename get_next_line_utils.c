/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrey <marrey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:09:03 by marrey            #+#    #+#             */
/*   Updated: 2024/10/14 20:44:27 by marrey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//code to return a line excepts the characters after the new line character
#include "get_next_line.h"

char *ft_line_to_return(char    *str)
{
    int count;
    int len;
    char    *str_to_return;
    
    count = ft_checkfornewline(*str);
    str_to_return = ft_strdup(str, count);
    len = ft_strlen(str);
    ft_memmove(str, count, len - count)
    return(str_to_return);
}

int ft_checkfornewline(char *str)
{
    int count;

    count = 0;
    while (*str)
    {
        if (*str == '\n')
            return (count);
        *str++;
        count++;
    }
    return (0);
}

char	*ft_strdup(const char *str, size_t n)
{
	char	*new_str;
	size_t	lenght;

	lenght = ft_strlen(str);
	new_str = (char *)malloc((n + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str, n);
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
    
    while (*str)
        *str++;
    while (*str2add)
        *str = *str2add++;
    str2return = str;
    return (str2return);
}

char    ft_putstr(char  *str)
{
    while (*str)
    {
        write(1, *str, 1);
        *str++;
    }
}

//calloc -- standard memory allocation function that stands for contiguous allocation
//          it allocates memory for an array of elements, initializes all bits to zero
//          and returns a pointer to the allocated memory.
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
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
