/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:34:06 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/24 17:06:16 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = malloc((len1 + len2 + 1) * sizeof (char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
/* 
#include <stdio.h>

int	main(void)
{
	char const s1[] = "Hello ";
	char const s2[] = "World!";
	char *s;
	s = ft_strjoin(s1, s2);
	printf("%s\n", s);
	free(s);
} */