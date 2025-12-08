/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:24:16 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/24 15:38:17 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	s = malloc((end - start + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (start < end)
		s[i++] = s1[start++];
	s[i] = '\0';
	return (s);
}
/* 
#include <stdio.h>

int	main(void)
{
	char const s1[] = "+++===Hello World+=* ";
	char const set[] = "+= *";
	printf("%s\n", ft_strtrim(s1, set));
} */
