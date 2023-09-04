/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:39:19 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:39:21 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memset function writes len bytes of value c
(converted to an unsigned char) to the string b. */

// #include <stdlib.h> 
// #include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	i = -1;
	a = (unsigned char *)b;
	while (++i < len)
		a[i] = (unsigned char)c;
	return (b);
}

/* void print_array(int arr[], int n)
{
   for (int i = 0; i < n; i++)
      printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	int n = 10;
	int arr[n];
	int arr_two[n];

	memset(arr, -1, n * sizeof(arr[0]));
	print_array(arr, n);
	
	ft_memset(arr_two, -1, n * sizeof(arr[0]));
	print_array(arr_two, n);

	char a[7] = "string";
	char b[7] = "string";
	int c = 'a';

	memset(a, c, 3);
	printf("a: %s\n", a);
	
	ft_memset(b, c, 3);
	printf("b: %s\n", b);

	return 0;
} */
