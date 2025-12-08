/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:26:33 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/25 20:07:37 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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
	node1->next = node3;
	ft_lstdelone(node2, del);
	printf("after: ");
	tmp = node1;
	while (tmp)
	{
		printf("%s ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	ft_lstdelone(node1, del);
	ft_lstdelone(node3, del);
} */