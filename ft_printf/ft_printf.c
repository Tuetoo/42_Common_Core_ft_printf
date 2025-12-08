/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:11:53 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/08 10:40:28 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* 
static	void	ft_flag(const char *format, t_format *f)
{
	while (ft_strchr("-0# +",format[f->i]))
	{
		if (format[f->i] == '-')
			f->minus = 1;
		else if (format[f->i] == '0')
			f->zero = 1;
		else if (format[f->i] == '#')
			f->hash = 1;
		else if (format[f->i] == ' ')
			f->space = 1;
		else if (format[f->i] == '+')
			f->plus = 1;
		f->i++;
	}
	while (format[f->i] >= '0' && format[f->i] <= '9')
	{
		f->width = f->width * 10 + (format[f->i] - '0');
		f->i++;
	}
	if (format[f->i] == '.')
	{
		f->i++;
		f->dot = 1;
		while(format[f->i] >= '0' && format[f->i] <= '9')
		{
			f->precision = f->precision * 10 + (format[f->i] - '0');
			f->i++;
		}
	}
} */

static	void	ft_flag(const char *format, t_format *f)
{
	while (ft_strchr("-0# +", format[f->i]))
	{
		f->zero = (format[f->i] == '0') || f->zero;
		f->minus = (format[f->i] == '-') || f->minus;
		f->hash = (format[f->i] == '#') || f->hash;
		f->space = (format[f->i] == ' ') || f->space;
		f->plus = (format[f->i] == '+') || f->plus;
		f->i++;
	}
	while (format[f->i] >= '0' && format[f->i] <= '9')
	{
		f->width = f->width * 10 + (format[f->i] - '0');
		f->i++;
	}
	if (format[f->i] == '.')
	{
		f->dot = 1;
		f->i++;
		while (format[f->i] >= '0' && format[f->i] <= '9')
		{
			f->precision = f->precision * 10 + (format[f->i] - '0');
			f->i++;
		}
	}
}

static int	ft_format(t_format *f, va_list args)
{
	int	count;

	count = 0;
	if (f->type == 'c')
		count = ft_putchar_format((char)va_arg(args, int), f);
	else if (f->type == 's')
		count = ft_putstr_format(va_arg(args, char *), f);
	else if (f->type == 'p')
		count = ft_putpointer_format(va_arg(args, void *), f);
	else if (f->type == 'd' || f->type == 'i')
		count = ft_putdigit_format(va_arg(args, int), f);
	else if (f->type == 'u')
		count = ft_putnbr_base(va_arg(args, unsigned int), "0123456789", f);
	else if (f->type == 'x')
		count = ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef", f);
	else if (f->type == 'X')
		count = ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", f);
	else if (f->type == '%')
		count = ft_putchar_format('%', f);
	return (count);
}

static void	ft_reset(t_format *f)
{
	f->width = 0;
	f->precision = 0;
	f->dot = 0;
	f->type = 0;
	f->zero = 0;
	f->minus = 0;
	f->hash = 0;
	f->space = 0;
	f->plus = 0;
}

static int	handle_format(const char *format, t_format *f, va_list args)
{
	int	count;

	f->i++;
	ft_reset(f);
	ft_flag(format, f);
	if (f->minus)
		f->zero = 0;
	if (f->plus)
		f->space = 0;
	f->type = format[f->i];
	if (!ft_strchr("cspdiuxX%", f->type))
		count = write(1, &format[f->i], 1);
	else
		count = ft_format(f, args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	t_format	f;

	ft_bzero(&f, sizeof(t_format));
	count = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[f.i])
	{
		if (format[f.i] == '%')
			count += handle_format(format, &f, args);
		else
			count += write(1, &format[f.i], 1);
		f.i++;
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

	ft_printf("ft_printf: %i\n", INT_MIN);
	printf("printf: %i\n", INT_MIN);

	ft_printf("ft_printf: %u\n", INT_MIN);
	printf("printf: %u\n", INT_MIN);

	ft_printf("ft_printf: %x\n", 255);
	printf("printf: %x\n", 255);

	ft_printf("ft_printf: %X\n", 255);
	printf("printf: %X\n", 255);

	ft_printf("ft_printf: %%\n");
	printf("printf: %%\n");

	ft_printf("ft_printf: %.0d\n", 0);
	printf("printf: %.0d\n", 0);

	ft_printf("ft_printf: %+05d\n", 42);
	printf("printf: %+05d\n", 42);

	ft_printf("ft_printf: %-5d\n", 42);
	printf("printf: %-5d\n", 42);

	ft_printf("ft_printf: %.3d\n", 12345);
	printf("printf: %.3d\n", 12345);

	ft_printf("ft_printf: %05d\n", 42);
	printf("printf: %05d\n", 42);

	ft_printf("ft_printf: %10.3d\n", 42);
	printf("printf: %10.3d\n", 42);

	ft_printf("ft_printf: %-10.5d\n", -42);
	printf("printf: %-10.5d\n", -42);

	ft_printf("ft_printf: %10x\n", 255);
	printf("printf: %10x\n", 255);

	ft_printf("ft_printf: %-10x\n", 255);
	printf("printf: %-10x\n", 255);

	ft_printf("ft_printf: %010x\n", 255);
	printf("printf: %010x\n", 255);

	ft_printf("ft_printf: %10.5x\n", 255);
	printf("printf: %10.5x\n", 255);

	ft_printf("ft_printf: %0x\n", 255);
	printf("printf: %0x\n", 255);

	ft_printf("ft_printf: %#10x\n", 255);
	printf("printf: %#10x\n", 255);
	
	ft_printf("ft_printf: %-20p\n", p);
	printf("printf: %-20p\n", p);

	ft_printf("ft_printf: %-20p\n", NULL);
	printf("printf: %-20p\n", NULL);

	ft_printf("ft_printf: %.0u\n", 123);
	printf("printf: %.0u\n", 123);

	ft_printf("ft_printf: %05u\n", 123);
	printf("printf: %05u\n", 123);

	ft_printf("ft_printf: %-5u\n", 123);
	printf("printf: %-5u\n", 123);

	ft_printf("ft_printf: %10.0d\n", 0);
	printf("printf: %10.0d\n", 0);

	ft_printf("ft_printf: % .10d\n", 42);
	printf("printf: % .10d\n", 42);

	ft_printf("ft_printf: % .10d\n", -42);
	printf("printf: % .10d\n", -42);

	ft_printf("ft_printf: % .10d\n", 0);
	printf("printf: % .10d\n", 0);

	ft_printf("ft_printf: %+0d\n", 42);
	printf("printf: %+0d\n", 42);

	ft_printf("ft_printf: %#x\n", 0);
	printf("printf: %#x\n", 0);

	ft_printf("ft_printf: %.2s\n", "");
	printf("printf: %.2s\n", "");

	ft_printf("ft_printf: %-10.10u\n", 1);
	printf("printf: %-10.10u\n", 1);

	//char *null_str = NULL;

	// ft_printf("ft_printf: %0.1s\n", str);
	// printf("printf: %0.1s\n", str);

} */
