/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:22:51 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/08 10:39:31 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_format(char *s, t_format *f)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] && (!f->dot || i < f->precision))
		i++;
	if (!f->minus)
		count += ft_putnchar(' ', f->width - i);
	count += write(1, s, i);
	if (f->minus)
		count += ft_putnchar(' ', f->width - i);
	return (count);
}
