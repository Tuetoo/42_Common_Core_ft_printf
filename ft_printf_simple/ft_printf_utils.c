/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:41:35 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/07 11:17:21 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putpointer(void *p)
{
	if (!p)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x")
		+ ft_putnbr_base((unsigned long)p, "0123456789abcdef"));
}

int	ft_putdigit(int num)
{
	long	n;
	char	c;
	int		count;

	n = num;
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	if (n / 10 > 0)
		count += ft_putdigit(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	int	len;
	int	count;

	count = 0;
	len = 0;
	while (base[len])
		len++;
	if (!base || len < 2)
		return (0);
	if (n >= (unsigned long)len)
		count += ft_putnbr_base(n / len, base);
	count += ft_putchar(base[n % len]);
	return (count);
}
