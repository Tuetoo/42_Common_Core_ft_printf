/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:35:11 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 09:38:52 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
		p[i++] = 0;
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char s1[20] = "Hello world!";
	char s2[20] = "Hello world!";
	size_t i = 0;
	size_t j = 0;

	ft_bzero(s1, 10);
	printf("ft: ");
	while (i < 20)
	{
		if(!s1[i])
			printf("0");
		printf("%c", s1[i]);
		i++;
	}
	printf("\n");
	bzero(s2, 10);
	printf("bzero: ");
	while (j < 20)
        {
                if(!s2[j])
                        printf("0");
                printf("%c", s2[j]);
                j++;
        }
        printf("\n");
}*/
