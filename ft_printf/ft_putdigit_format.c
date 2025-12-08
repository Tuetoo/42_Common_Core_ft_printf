/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:24:09 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/08 10:38:55 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_sign(char *s, t_format *f)
{
	if (s[0] == '-')
		return (write(1, "-", 1));
	if (f->plus)
		return (write(1, "+", 1));
	if (f->space)
		return (write(1, " ", 1));
	return (0);
}

static int	put_padding(t_format *f, int len, char *s, int pad)
{
	int	count;

	count = 0;
	if (!f->minus && !(f->zero && !f->dot))
		count += ft_putnchar(' ', pad);
	count += put_sign(s, f);
	if (f->zero && !f->dot && !f->minus)
		count += ft_putnchar('0', pad);
	if (f->dot && f->precision > len - (s[0] == '-'))
		count += ft_putnchar('0', f->precision - (len - (s[0] == '-')));
	if (len)
		count += write(1, s + (s[0] == '-'), len - (s[0] == '-'));
	if (f->minus)
		count += ft_putnchar(' ', pad);
	return (count);
}

int	ft_putdigit_format(long long num, t_format *f)
{
	char	*s;
	int		len;
	int		pad;
	int		count;

	count = 0;
	s = ft_itoa(num);
	if (!s)
		return (-1);
	len = ft_strlen(s);
	if (num == 0 && f->dot && f->precision == 0)
		len = 0;
	pad = f->width - len - (f->plus || f->space);
	if (f->dot && f->precision > len - (num < 0))
		pad -= f->precision - (len - (num < 0));
	if (pad < 0)
		pad = 0;
	count += put_padding(f, len, s, pad);
	return (free(s), count);
}
