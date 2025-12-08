/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:09:16 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 14:17:19 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("%d\n", 'z');
	printf("%d\n",ft_toupper('z'));
	printf("%d\n", toupper('z'));
}*/
