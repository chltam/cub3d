/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:44:02 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:44:05 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

/* Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’. */

/* char ft_toupper(unsigned int n, char c)
{
	if (n < 3)
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
		else
			return (c);
	}
	return (c);
}
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mapped;

	i = 0;
	mapped = malloc(ft_strlen(s) + 1);
	if (!mapped)
		return (NULL);
	while (s[i])
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}

/* int main(void)
{
	char const *str = "hello";
	char (*ft_toupper_ptr)(unsigned int, char) = &ft_toupper;

	char *new = ft_strmapi(str, ft_toupper_ptr);
	printf("new: %s\n", new);
	return 0;
} */
