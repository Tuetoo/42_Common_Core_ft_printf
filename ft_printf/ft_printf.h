/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:12:06 by jiezhang          #+#    #+#             */
/*   Updated: 2025/11/14 16:33:52 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_format
{
	int		width;
	int		precision;
	int		dot;
	char	type;
	int		zero;
	int		minus;
	int		hash;
	int		space;
	int		plus;
	int		i;
}	t_format;

int	ft_printf(const char *format, ...);
int	ft_putnchar(char c, int n);
int	ft_putchar_format(char c, t_format *f);
int	ft_putstr_format(char *s, t_format *f);
int	ft_putdigit_format(long long num, t_format *f);
int	ft_putnbr_base(unsigned long n, char *base, t_format *f);
int	ft_putpointer_format(void *p, t_format *f);

#endif
