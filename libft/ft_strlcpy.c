/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:44:56 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:44:59 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		src_size;
	size_t	i;

	i = 0;
	src_size = ft_strlen(src);
	if (dstsize == 0)
		return (src_size);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}

/* int	main(void)
{
	char src[6], dest[6], dest_two[6];
	size_t total_len = 0;

   	strcpy(src,  "hello");
   	strcpy(dest, "");
   	strcpy(dest_two, "");

	total_len = ft_strlcpy(dest, src, 1);
	printf("result: %s\n", dest);
	printf("len: %zu\n", total_len);

	total_len = strlcpy(dest_two, src, 1);
	printf("result: %s\n", dest_two);
	printf("len: %zu\n", total_len);
	return (0);
} */
