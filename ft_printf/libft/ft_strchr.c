/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:23:47 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 15:21:01 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if ((char) c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	const char s[10] = "Hello!";
	printf("FT: %s\n", ft_strchr(s, 'l'));
	printf("strchr: %s\n", strchr(s, 'l'));
} */