/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:32:44 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/10 16:32:47 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void my_toupper(char *s)
{
    while(*s)
	{
		if (*s >= 'a' && *s <= 'z')
        	*s = *s - 32;
		s++;
	}
} */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	if (!lst || !f)
		return ;
	curr = lst;
	while (curr)
	{
		(*f)(curr->content);
		curr = curr->next;
	}
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
	void (*my_toupper_ptr)(char *) = &my_toupper;
	ft_lstiter(head, my_toupper_ptr);
	printf("AFTER\n");
	write(1, head->content, 3);
	write(1, "\n", 1);
	tmp = head;
	while (tmp)
	{
		write(1, tmp->content, 3);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	return 0;
} */