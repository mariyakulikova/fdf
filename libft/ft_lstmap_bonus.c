/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:54:22 by mkulikov          #+#    #+#             */
/*   Updated: 2023/12/05 12:24:24 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	tmp = lst;
	while (tmp)
	{
		node = ft_lstnew(f(lst->content));
		ft_lstadd_back(&head, node);
		if (!node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (head);
}
// #include <stdio.h>

// void	*map_function(void *content)
// {

// 	char *modified_content = ft_strjoin((char *)content, " Modified");
// 	return (modified_content);
// }
// void	del(void *content)
// {
// 	free(content);
// }
// int main(void)
// {
// 	t_list *list = ft_lstnew("Element 1");
// 	ft_lstadd_back(&list, 0);
// 	ft_lstadd_back(&list, 0);
// 	t_list *mapped_list = ft_lstmap(list, &map_function, &del);
// 	printf("Original List:\n");
// 	while (list)
// 	{
// 		printf("%s\n", (char *)list->content);
// 		list = list->next;
// 	}
// 	printf("\nMapped List:\n");
// 	while (mapped_list)
// 	{
// 		printf("%s\n", (char *)mapped_list->content);
// 		t_list *temp = mapped_list;
// 		mapped_list = mapped_list->next;
// 		free(temp->content); // Free the content before freeing the element
// 		free(temp);
// 		ft_lstclear(&list, del);
// 	}
// 	return (0);
// }
