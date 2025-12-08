/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:40:45 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/25 19:24:33 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
/* 
#include <stdio.h>

int	main(void)
{
	int a = 10;
	int b = 5;
	t_list *head = ft_lstnew(&a);
	t_list *new_node = ft_lstnew(&b);
	ft_lstadd_front(&head, new_node);

	t_list *tmp = head;
	while(tmp)
	{
		printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp)
	{
		t_list *next = tmp->next;
		free(tmp);
		tmp = next;
	}
} */