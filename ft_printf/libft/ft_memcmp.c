/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:32:38 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 16:59:37 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char s1[] = "Hello World!";
	const char s2[] = "Hello Jenny!";
	printf("FT: %d\n", ft_memcmp(s1, s2, 10));
	printf("memcmp: %d\n", memcmp(s1, s2, 10));
} */