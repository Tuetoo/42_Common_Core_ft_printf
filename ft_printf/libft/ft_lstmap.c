/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:09:05 by jiezhang          #+#    #+#             */
/*   Updated: 2025/10/26 09:38:19 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
/* 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void	*to_upper(void *content)
{
	char *s = strdup((char *)content);
	int i = 0;

	if (!s)
		return (NULL);
	while (s[i])
	{
		s[i] = toupper(s[i]);
		i++;
	}
	return (s);
}

void del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *lst = NULL;
	t_list *new = NULL;
	
	ft_lstadd_back(&lst, ft_lstnew(strdup("Hello ")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("World ")));
	
	new = ft_lstmap(lst, &to_upper, &del);
	t_list *tmp = new;
	while (tmp)
	{
		printf("%s", (char *)(tmp->content));
		tmp = tmp->next;
	}
	printf("\n");
	ft_lstclear(&lst, &del);
	ft_lstclear(&new, &del);
} */