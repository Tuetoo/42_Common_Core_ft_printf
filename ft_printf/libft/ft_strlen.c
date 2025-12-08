/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:51:51 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 09:37:39 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("ft: %ld\n", ft_strlen("Hello World!"));
	printf("strlen: %ld\n", strlen("Hello World!"));
}*/
