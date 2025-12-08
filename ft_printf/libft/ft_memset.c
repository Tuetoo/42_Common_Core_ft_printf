/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:10:08 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 09:38:08 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
		p[i++] = (unsigned char)c;
	return (s);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[20] = "Hello, world!";
	char s2[20] = "Hello, world!";
	ft_memset(s1, 'A', 5);
	printf("ft: %s\n", s1);
	memset(s2, 'A', 5);
	printf("memset: %s\n", s2);
}*/
