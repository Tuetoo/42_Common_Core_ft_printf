/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:01:52 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 18:01:59 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && little[j]
			&& (i + j) < len)
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
/* 
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	const char big[] = "Hello World!";
	const char little[] = "World";

	printf("FT: %s\n", ft_strnstr(big, little, 12));
	printf("strnstr: %s\n", strnstr(big, little, 12));
} */
// cc with -lbsd flag