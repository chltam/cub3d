/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:32:29 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/10 16:32:31 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	del(void *ptr)
{
	free(ptr);
}

void my_toupper(char *s)
{
    while(*s)
	{
		if (*s >= 'a' && *s <= 'z')
        	*s = *s - 32;
		s++;
	}
} */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	node = ft_lstnew(f(lst->content));
	new = node;
	lst = lst->next;
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

/* int main(void)
{
	char *s = "hello";

	t_list *head = ft_lstnew(s);
	write(1, head->content, 5);
	write(1, "\n", 1);

	t_list *new = malloc(sizeof(t_list));
	ft_lstadd_front(&head, new);		printf("HERE\n");

	
	head->content = malloc(3);
	ft_memcpy(head->content, "bye", 3);
	t_list *tmp = head;
	while (tmp)
	{
		write(1, tmp->content, 3);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	void *(*my_toupper_ptr)(char *) = &&my_toupper;
	void (*del_ptr)(void *) = &del;
	t_list *mapped = ft_lstmap(head, my_toupper_ptr, del_ptr);
	printf("AFTER:\n");
	while (mapped)
	{
		write(1, mapped->content, 5);
		write(1, "\n", 1);
		mapped = mapped->next;
	}
	return 0;
} */