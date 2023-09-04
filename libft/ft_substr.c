/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:42:12 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:42:16 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’ */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	mlen;

	i = 0;
	if (!s || !s[0] || (size_t)start > ft_strlen(s))
	{
		sub = malloc(1);
		sub[0] = '\0';
		return (sub);
	}
	if (len < ft_strlen(s))
		mlen = len;
	else
		mlen = ft_strlen(s);
	sub = malloc(mlen + 1);
	if (!sub)
		return (NULL);
	while (i < len && i < ft_strlen(s))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/* int main(void)
{
	char const *s = "0123456789";
	unsigned int start = 9;
	size_t len = 10;

	char *sub = ft_substr(s, start, len);
	printf("sub: %s\n", sub);

	return 0;
} */
