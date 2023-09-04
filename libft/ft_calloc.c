/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:35:02 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:35:06 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

	// if (nmemb == 0)
	// {
	// 	ptr = malloc(1);
	// 	ptr = (char *)ptr;
	// 	ptr[0] = '\0';
	// 	return (ptr);
	// }

/* void print_array(int arr[], int n)
{
   for (int i = 0; i < n; i++)
      printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int size = 0;
	int *array;

	printf("Array-Groesse eingeben: ");
	scanf("%d", &size);

	// Speicher reservieren
	array = (int *) calloc(size, 0);

	if (array != NULL)
		printf("\nSpeicher ist reserviert\n");
	else
		printf("\nKein freier Speicher vorhanden.\n");

	free(array);
	array = NULL;
	
	printf("HERE\n");
	// Speicher reservieren
	array = (int *) ft_calloc(size, sizeof(int));

	if (array != NULL)
		printf("\nSpeicher ist reserviert\n");
	else
		printf("\nKein freier Speicher vorhanden.\n");

	print_array(array, 10);

	free(array);
	array = NULL;
	return 0;
} */
