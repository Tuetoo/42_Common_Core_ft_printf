/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:16:34 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/25 17:55:38 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = n;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static char	*ft_revstr(char *str)
{
	size_t	i;
	size_t	len;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len -1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	i;

	i = 0;
	nbr = n;
	str = malloc(sizeof(char) * (ft_len(n) + 1));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[i++] = '0';
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		str[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_revstr(str);
	return (str);
}
/* 
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *s = ft_itoa(INT_MIN);
	printf("%s\n", s);
	free(s);
} */