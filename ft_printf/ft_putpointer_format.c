/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 09:43:18 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/08 10:39:20 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer_format(void *p, t_format *f)
{
	int	count;
	int	pad;

	count = 0;
	pad = 0;
	if (!p)
	{
		pad = f->width - 5;
		if (pad < 0)
			pad = 0;
		if (!f->minus)
			count += ft_putnchar(' ', pad);
		count += write(1, "(nil)", 5);
		if (f->minus)
			count += ft_putnchar(' ', pad);
		return (count);
	}
	f->hash = 1;
	return (ft_putnbr_base((unsigned long)p, "0123456789abcdef", f));
}
