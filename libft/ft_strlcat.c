/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:44:40 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:44:44 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	i = ft_strlen(dest);
	j = 0;
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[j]));
}

/* int	main(void)
{
	char src[7], dest[12], dest_two[12];
	size_t total_len = 0;

   	strcpy(src,  " world");
   	strcpy(dest, "hello");
   	strcpy(dest_two, "hello");

	total_len = ft_strlcat(dest, src, 12);
	printf("result: %s\n", dest);
	printf("len: %zu\n", total_len);

	// total_len = strlcat(dest_two, src, 12);
	// printf("result: %s\n", dest_two);
	// printf("len: %zu\n", total_len);

	char dst[10] = "a";
	printf("len: %ld\n", ft_strlcat(dst, "lorem ipsum dolor sit amet", 0));
	printf("res: %s\n", dst);

	return (0);
} */
