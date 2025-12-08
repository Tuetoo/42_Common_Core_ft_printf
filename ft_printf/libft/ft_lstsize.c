/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:51:03 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/25 18:11:56 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/* 
#include <stdio.h>

int	main(void)
{
	t_list *head;
	t_list *node1;
	t_list *node2;
	int	a = 10;
	int b = 20;

	node1 = ft_lstnew(&a);
	node2 = ft_lstnew(&b);
	head = node1;
	ft_lstadd_front(&head, node2);
	printf("%d\n", ft_lstsize(head));

	t_list *tmp;
	t_list *next;
	tmp = head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
} */