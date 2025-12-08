/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:09:28 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/24 21:32:26 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	ft_putnbr_fd(int n, int fd)
{
	char	*s;
	s = ft_itoa(n);
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	free(s);
} */
void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr / 10 > 0)
		ft_putnbr_fd(nbr / 10, fd);
	c = (nbr % 10) + '0';
	write(fd, &c, 1);
}
/* 
#include "limits.h"

int	main(void)
{
	ft_putnbr_fd(INT_MIN, 1);
	write(1, "\n", 1);
} */