/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:10:41 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/25 12:16:20 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/* 
#include <stdio.h>
int	main(void)
{
	int a = 10;
	t_list *node = ft_lstnew(&a);
	if (!node)
		return (0);
	printf("content: %d\n", *(int *)node->content);
	printf("next: %p\n", (void *)node->next);
	free(node);
} */