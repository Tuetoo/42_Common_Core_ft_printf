/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:50:40 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 09:35:57 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("ft: %d\n", ft_isalpha('\0'));
	printf("is: %d\n", isalpha('\0'));

	printf("ft: %d\n", ft_isalpha('a'));
	printf("is: %d\n", isalpha('a'));
}*/
