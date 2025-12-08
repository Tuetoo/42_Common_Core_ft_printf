/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:20:50 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/08 10:38:43 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_format(char c, t_format *f)
{
	int	count;

	count = 0;
	if (!f->minus)
		count += ft_putnchar(' ', f->width - 1);
	count += write(1, &c, 1);
	if (f->minus)
		count += ft_putnchar(' ', f->width - 1);
	return (count);
}
