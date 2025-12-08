/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:41:13 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/25 19:22:14 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/* 
#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;

	t_list *node1;
	t_list *node2;
	t_list *head;

	node1 = ft_lstnew(&a);
	node2 = ft_lstnew(&b);
	head = node1;
	ft_lstadd_back(&head, node2);

	t_list *tmp = head;
	while(tmp)
	{
		printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}

	tmp = head;
	t_list *next;
	while(tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}  */