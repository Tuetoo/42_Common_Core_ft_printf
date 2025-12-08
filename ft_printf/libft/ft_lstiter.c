/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:50:03 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/25 21:07:47 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* 
#include <stdio.h>

void	print_content(void *content)
{
	printf("%d ", *(int *)content);
}

int	main(void)
{
	int a = 10;
	int b = 20;
	int c = 30;

	t_list *node1 = ft_lstnew(&a);
	t_list *node2 = ft_lstnew(&b);
	t_list *node3 = ft_lstnew(&c);

	node1->next = node2;
	node2->next = node3;

	ft_lstiter(node1, print_content);
	printf("\n");
} */