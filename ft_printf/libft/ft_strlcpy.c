/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:03:28 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 13:56:54 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	if (srclen <= size - 1)
		ft_memcpy(dst, src, srclen + 1);
	else
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srclen);
}

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	srclen;
// 	size_t	i;

// 	srclen = ft_strlen(src);
// 	i = 0;
// 	if (size == 0)
// 		return (srclen);
// 	while (i < size - 1 && src[i])
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (srclen);
// }
/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char dst1[30];
	char dst2[30];
	const char src[20] = "Hello world!";
	printf("FT: %zu dst1: %s\n", ft_strlcpy(dst1, src, 10), dst1);
	printf("strlcpy: %zu dst2: %s\n", strlcpy(dst2, src, 10), dst2);
}*/
// cc with -lbsd flag
