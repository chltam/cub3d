/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:40:52 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:40:54 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

/* Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’. */

/* void my_toupper(unsigned int n, char *s)
{
    if (s[n] >= 'a' && s[n] <= 'z')
        s[n] = s[n] - 32;
} */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* int main(void)
{
	char str[6] = "hello";
	void (*my_toupper_ptr)(unsigned int, char*) = my_toupper;

	ft_striteri(str, my_toupper_ptr);
	printf("new: %s\n", str);
	return 0;
} */
