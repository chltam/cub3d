/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:20:02 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/10 16:20:04 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	del(void *ptr)
{
	free(ptr);
} */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* int main(void)
{
	char *s = "hello";

	t_list *head = ft_lstnew(s);
	write(1, head->content, 5);
	write(1, "\n", 1);

	t_list *new = malloc(sizeof(t_list));
	ft_lstadd_front(&head, new);
	
	head->content = malloc(3);
	ft_memcpy(head->content, "bye", 3);
	t_list *tmp = head;
	while (tmp)
	{
		write(1, tmp->content, 3);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
		void (*del_ptr)(void *) = &del;
	ft_lstdelone(head->next, del_ptr);
	tmp = head;
	while (tmp)
	{
		write(1, tmp->content, 3);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	return 0;
} */
