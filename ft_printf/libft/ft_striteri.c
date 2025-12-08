/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:16:24 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/24 20:06:33 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
#include <stdio.h>
#include <ctype.h>

void	to_upper(unsigned int i, char *c)
{
	(void)i;
	if(*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	main(void)
{
	char s[] = "Hello World!";
	ft_striteri(s, to_upper);
	printf("%s\n", s);
} */