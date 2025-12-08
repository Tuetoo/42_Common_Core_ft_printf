/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:49:49 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 15:21:16 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if ((char)c == '\0')
		return ((char *)(s + i));
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
			return ((char *)(s + i));
	}
	return (NULL);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	const char s[10] = "Hello!";
	printf("FT: %s\n", ft_strrchr(s, 'l'));
	printf("strrchr: %s\n", strrchr(s, 'l'));
} */