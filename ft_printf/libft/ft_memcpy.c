/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 07:20:42 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/26 15:16:21 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest || !src)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char src[20] = "Hello, world!";
	char dest1[20];
	char dest2[20];
	ft_memcpy(dest1, src, 10);
	dest1[10] = '\0';
	printf("FT: %s\n", dest1);
	memcpy(dest2, src, 10);
	dest2[10] = '\0';
	printf("memcpy: %s\n", dest2);
} */