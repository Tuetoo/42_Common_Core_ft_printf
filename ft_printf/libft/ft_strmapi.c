/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:02:21 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/24 19:12:59 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/* 
#include <stdio.h>
#include <ctype.h>

char	to_upper(unsigned int i, char c)
{
	(void)i;
	if(c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char const s[] = "Hello World!";
	char *str = ft_strmapi(s, to_upper);
	printf("%s\n", str);
	free(str);
} */