/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:41:32 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/07 11:11:29 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_putpointer(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_putdigit(va_arg(args, int));
	else if (c == 'u')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_format(format[i], args);
		}
		else
			count += write(1, &format[i++], 1);
		i++;
	}
	va_end(args);
	return (count);
}

/* 
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int a = 42;
	void *p = &a;

	ft_printf("ft_printf: %c\n", 'a');
	printf("printf: %c\n", 'a');

	ft_printf("ft_printf: %s\n", "Hello World");
	printf("printf: %s\n", "Hello World");
	
	ft_printf("ft_printf: %d\n", INT_MIN);
	printf("printf: %d\n", INT_MIN);

	ft_printf("ft_printf: %d\n", INT_MAX);
	printf("printf: %d\n", INT_MAX);

	ft_printf("ft_printf: %d\n", 0);
	printf("printf: %d\n", 0);

	ft_printf("ft_printf: %u\n", INT_MIN);
	printf("printf: %u\n", INT_MIN);

	ft_printf("ft_printf: %x\n", 255);
	printf("printf: %x\n", 255);

	ft_printf("ft_printf: %X\n", 255);
	printf("printf: %X\n", 255);
} */
