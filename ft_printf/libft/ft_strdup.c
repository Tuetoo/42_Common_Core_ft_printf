/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:26:06 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/24 13:32:32 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	slen;
	char	*d;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	d = malloc((slen + 1) * sizeof(char));
	if (!d)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
/* 
char	*ft_strdup(const char *s)
{
	char *d;
	
	d = malloc((ft_strlen(s)+1) * sizeof(char));
	if (!d)
		return (NULL);
	ft_memcpy(d, s, ft_strlen(s)+1);
	return(d);
} */
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	const char s[] = "Hello World!";
	char *d1;
	char *d2;
	d1 = ft_strdup(s);
	d2 = strdup(s);
	if (!d1 || !d2)
	{
		free(d1);
		free(d2);
		return (1);
	}
	printf("FT: %s\n", d1);
	printf("strdup: %s\n", d2);
	free(d1);
	free(d2);
} */