/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:38:54 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:38:57 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* memcpy just loops, while memmove performs a test to determine
which direction to loop in to avoid corrupting the data. */

// #include <stdio.h> 
// #include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	if (!dst && !src)
		return (0);
	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	if (dst <= src)
	{
		while (len--)
			*dst_cpy++ = *src_cpy++;
	}
	else if (dst > src)
	{
		dst_cpy += len - 1;
		src_cpy += len - 1;
		while (len--)
			*dst_cpy-- = *src_cpy--;
	}
	return (dst);
}

/* void print_array(int arr[], int n)
{
   for (int i = 0; i < n; i++)
      printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	int n = 5;
	int arr[5] = { 1, 2, 3, 4, 5 };
	int arr_two[5] = { 0 };

	memmove(arr_two, arr, n * sizeof(arr[0]));
	print_array(arr_two, n);

	int arr_three[5] = { 1, 2, 3, 4, 5 };
	int arr_four[5] = { 0 };
	ft_memmove(arr_four, arr_three, n * sizeof(arr[0]));
	print_array(arr_four, n);

	char a[7] = "string";
	char b[7] = "world";

	memmove(b, a, 7);
	printf("b: '%s'\n", b);

	char c[7] = "string";
	char d[7] = "world";

	ft_memmove(d, c, 7);
	printf("b: '%s'\n", d);

	return 0;
} */
