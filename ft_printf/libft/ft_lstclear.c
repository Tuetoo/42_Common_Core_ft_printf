/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:08:53 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/25 20:47:37 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
/* 
#include <stdio.h>
#include <string.h>

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	char *s1 = strdup("node1");
	char *s2 = strdup("node2");
	char *s3 = strdup("node3");

	t_list *node1 = ft_lstnew(s1);
	t_list *node2 = ft_lstnew(s2);
	t_list *node3 = ft_lstnew(s3);

	node1->next = node2;
	node2->next = node3;
	printf("before: ");
	t_list *tmp = node1;
	while (tmp)
	{
		printf("%s ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	ft_lstclear(&node1, del);
	printf("after: %p\n", (void *)node1);
}  */