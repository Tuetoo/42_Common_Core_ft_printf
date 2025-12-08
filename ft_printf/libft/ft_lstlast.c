/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:18:01 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/25 18:38:53 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/* 
#include <stdio.h>

int main(void)
{
	int a = 20;
	int b = 10;
	t_list *node1;
	t_list *node2;
	t_list *head;

	node1 = ft_lstnew(&a);
	node2 = ft_lstnew(&b);
	head = node1;
	ft_lstadd_front(&head, node2);
	if (ft_lstlast((head)))
		printf("%d\n", *(int *)ft_lstlast(head)->content);

	t_list *tmp = head;
	t_list *next;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
} */