/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:18:42 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/23 14:20:31 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

/* #include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("%d\n", 'Z');
	printf("%d\n",ft_tolower('Z'));
	printf("%d\n", tolower('Z'));
} */