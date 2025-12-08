/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:39:22 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/25 15:51:33 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	free_array(char **array, size_t i)
{
	while (i > 0)
		free(array[--i]);
	free(array);
}

static char	*newword(char const *s, char c, size_t *i)
{
	size_t	start;
	char	*array;

	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	array = ft_substr(s, start, *i - start);
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	j;
	size_t	count;

	if (!s)
		return (NULL);
	count = wordcount(s, c);
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count)
	{
		array[j] = newword(s, c, &i);
		if (!array[j])
		{
			free_array(array, j);
			return (NULL);
		}
		j++;
	}
	array[j] = NULL;
	return (array);
}

// char	**ft_split(char const *s, char c)
// {
// 	char	**array;
// 	size_t	i;
// 	size_t	start;
// 	size_t	end;

// 	if (!s)
// 		return (NULL);
// 	array = malloc(sizeof(char *) * (wordcount(s, c) + 1));
// 	if (!array)
// 		return (NULL);
// 	i = 0;
// 	start = 0;
// 	while(i < wordcount(s, c))
// 	{
// 		while (s[start] && s[start] == c)
// 			start++;
// 		end = start;
// 		while (s[end] && s[end] !=c )
// 			end++;
// 		array[i] = ft_substr(s, start, end - start);
// 		if (!array[i])
// 			return (free_array(array, i), NULL);
// 		i++;	
// 		start = end;	
// 	}
// 	array[i] = NULL;
// 	return (array);
// }

/* 
#include <stdio.h>

int	main(void)
{
	char	*s = "    Hello    World  This is a good day ";
	char	c = ' ';
	char	**array = ft_split(s, c);
	size_t	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		free(array[i]);
		i++;
	}
	free(array);
} */
