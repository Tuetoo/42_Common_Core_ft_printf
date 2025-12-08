/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:29:46 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/26 11:02:35 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb != 0 && size > (size_t)(-1) / nmemb)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

// void	*ft_calloc(size_t nmemb, sizt_t size)
// {
// 	void	*p;
// 	if(nmemb != 0 && (nmemb * size) != size)
// 		return (NULL);
// 		p = malloc(nmemb * size);
// 	if (!p)
// 		return (NULL);
// 	ft_bzero(p, nmemb * size);
// 	return (p);
// }

/* 
int	main(void)
{
	int i = 0; 
	int j = 0;
	int *arr1 = ft_calloc(5, sizeof (int));
	int *arr2 = calloc(5, sizeof(int));
	if (!arr1 || !arr2 )
		return (1);
	printf("FT: ");
	while (i < 5)
		printf("%d ", arr1[i++]);
	printf("\n");
	free(arr1);
	printf("calloc: ");
	while (j < 5)
		printf("%d ", arr2[j++]);
	printf("\n");
	free(arr2);
} */