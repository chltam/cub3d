/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:40:37 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:40:40 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = ft_strlen(src) + 1;
	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char *src = "stuff";
	char *dup = ft_strdup(src);
	printf("dup: '%s'\n", dup);
	free(dup);
	dup = strdup(src);
	printf("dup: '%s'\n", dup);
	free(dup);
	return (0);
} */
