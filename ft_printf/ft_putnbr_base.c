/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:25:34 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/08 10:39:10 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned long n, int baselen)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)baselen)
	{
		n /= baselen;
		len++;
	}
	return (len);
}

static int	put_prefix(unsigned long n, t_format *f)
{
	int	count;

	count = 0;
	if (f->type == 'p' || (f->hash && n != 0
			&& (f->type == 'x' || f->type == 'X')))
	{
		if (f->type == 'p' || f->type == 'x')
			count += write(1, "0x", 2);
		else
			count += write(1, "0X", 2);
	}
	return (count);
}

static int	put_nbr(unsigned long n, char *base)
{
	int	count;
	int	baselen;

	count = 0;
	baselen = ft_strlen(base);
	if (n >= (unsigned long)baselen)
		count += put_nbr(n / baselen, base);
	count += write(1, &base[n % baselen], 1);
	return (count);
}

static int	put_padding(unsigned long n, t_format *f, int pad, char *base)
{
	int	len;
	int	count;
	int	prefix;

	count = 0;
	prefix = 0;
	len = get_len(n, ft_strlen(base));
	if (n == 0 && f->dot && f->precision == 0 && f->type != 'p')
		len = 0;
	prefix = 2 * (f->type == 'p'
			|| (f->hash && n != 0 && (f->type == 'x' || f->type == 'X')));
	if (!f->minus && f->width > len + pad + prefix)
	{
		if (f->zero && !f->dot)
			count += ft_putnchar('0', f->width - len - pad - prefix);
		else
			count += ft_putnchar(' ', f->width - len - pad - prefix);
	}
	count += put_prefix(n, f);
	count += ft_putnchar('0', pad);
	if (!(n == 0 && f->dot && f->precision == 0 && f->type != 'p'))
		count += put_nbr(n, base);
	if (f->minus && f->width > len + pad + prefix)
		count += ft_putnchar(' ', f->width - len - pad - prefix);
	return (count);
}

int	ft_putnbr_base(unsigned long n, char *base, t_format *f)
{
	int	len;
	int	count;
	int	pad;

	count = 0;
	pad = 0;
	len = get_len(n, ft_strlen(base));
	if (n == 0 && f->dot && f->precision == 0 && f->type != 'p')
		len = 0;
	if (f->dot && f->precision > len)
		pad = f->precision - len;
	if (pad < 0)
		pad = 0;
	count += put_padding(n, f, pad, base);
	return (count);
}
