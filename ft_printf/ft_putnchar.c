/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:59:55 by jiezhang          #+#    #+#             */
/*   Updated: 2025/11/14 16:08:24 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnchar(char c, int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count += write(1, &c, 1);
		n--;
	}
	return (count);
}
