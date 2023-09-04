/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:34:46 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:34:50 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h> 
// #include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = -1;
	a = (unsigned char *)s;
	while (++i < n)
		a[i] = 0;
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

	bzero(arr, n * sizeof(arr[0]));
	print_array(arr, n);
	
	ft_bzero(arr_two, n * sizeof(arr[0]));
	print_array(arr_two, n);

	char a[7] = "string";
	char b[7] = "string";
	int c = 'a';

	bzero(a, 3);
	printf("a: '%s'\n", a);
	
	ft_bzero(b, 3);
	printf("b: '%s'\n", b);

	return 0;
} */
