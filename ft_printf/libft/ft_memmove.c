/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 07:42:58 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/24 13:25:06 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest || !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d <= s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char src[20] = "Hello World!";
	char dest1[18];
	char dest2[18];
	ft_memmove(dest1, src, 5);
	dest1[5] = '\0';
	printf("FT: %s\n", dest1);
	memmove(dest2, src, 5);
	dest2[5] = '\0';
	printf("memmove: %s\n", dest2);
} */
