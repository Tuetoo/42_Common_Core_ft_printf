/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:40:20 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 14:03:31 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j] && j < size - dstlen - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dstlen + srclen);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char dst1[50] = "Hello, World!";
	char dst2[50] = "Hello, World!";
	const char src[] = "This is a good day!";
	printf("FT: %zu dst1: %s\n", ft_strlcat(dst1, src, 40), dst1);
	printf("strlcpy: %zu dst2: %s\n", strlcat(dst2, src, 40), dst2);
}*/
// cc with -lbsd flag