/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:55:27 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 16:31:03 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	i = 0;
	p = (const unsigned char *)s;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char s[] = "Hello world!";
	printf("FT: %p\n", ft_memchr(s, 'w', 10));
	printf("memchr: %p\n", memchr(s, 'w', 10));
} */