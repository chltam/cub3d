/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:37:39 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:37:40 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	if (s == NULL)
		return (NULL);
	i = -1;
	a = (unsigned char *)s;
	while (++i < n)
	{
		if (a[i] == (unsigned char)c)
			return (&a[i]);
	}
	return (NULL);
}

/* void print_array(int arr[], int n)
{
   	for (int i = 0; i < n; i++)
      printf("%d ", arr[i]);
	
	printf("\n");
}

int main(void)
{
	char a[7] = "string";

	char *loc = memchr(a, 'i', 4);
	printf("loc: '%s'\n", loc);

	char c[7] = "string";

	char *loc_two = ft_memchr(c, 'i', 4);
    printf("loc_two: '%s'\n", loc_two);

	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf("%s\n", (char *)memchr(tab, -1, 7));
	printf("%s\n", (char *)ft_memchr(tab, -1, 7));

	return 0;
} */
