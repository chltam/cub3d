/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:44:29 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/07 16:44:31 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* size_t ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	unsigned char *a;
	unsigned char *b;

	i = 0;
	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (dst);
}

t_list	*ft_lstnew(void *content)
{
	t_list			*head;
	size_t			len;

	head = NULL;
	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	if (!content)
		head->content = NULL;
	else
	{
		len = ft_strlen(content);
		head->content = malloc(len);
		ft_memcpy(head->content, content, len);
	}
	head->next = NULL;
	return (head);
} */

/* void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	size;
	
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
} */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

/* int main(void)
{
	char *s = "hello";
	t_list *head = NULL;
	printf("zero size: %d\n", ft_lstsize(head));

	head = ft_lstnew(s);
	write(1, head->content, 5);
	write(1, "\n", 1);

	printf("first size: %d\n", ft_lstsize(head));
	t_list *new = malloc(sizeof(t_list));
	ft_lstadd_front(&head, new);
	printf("size: %d\n", ft_lstsize(head));
	
	head->content = malloc(3);
	ft_memcpy(head->content, "bye", 3);
	t_list *tmp = head;
	while (tmp)
	{
		write(1, tmp->content, 3);
		write(1, "\n", 1);
		tmp = tmp->next;
	}

	printf("CURRENT NODE:\n");
	write(1, head->content, 3);
	write(1, "\n", 1);

	head = ft_lstlast(head);
	printf("CURRENT NODE:\n");
	write(1, head->content, 3);
	write(1, "\n", 1);

	free(new->content);
	free(new);
	return 0;
}
 */