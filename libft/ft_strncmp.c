/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:43:46 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:43:47 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] == '\0' && i < n)
		return (-s2[i]);
	return (0);
}

/* int	main(void)
{
	const char *str = "abcdef";
	const char *str2 = "abcdefghijklmnop";

	int result = strncmp(str, str2, 6);
	printf("result: %d\n", result);
    result = ft_strncmp(str, str2, 6);
    printf("result: %d\n", result);
	return (0);
} */