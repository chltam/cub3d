/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:32:18 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:32:34 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer */

static int	find_size(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			size++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (size);
}

static int	find_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

/* static void ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
} */

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		size;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = -1;
	size = find_size(s, c);
	strs = (char **)malloc((size + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (++j < size)
	{
		while (s[i] == c)
			i++;
		len = find_len(s, c, i);
		strs[j] = ft_substr(s, i, len);
		if (!strs[j])
			return (NULL);
		i += len;
	}
	strs[j] = 0;
	return (strs);
}

/* int	main(void)
{
	char str[] = "lorem ipsum dolor sit amet,
	consectetur adipiscing elit. Sed non risus. Suspendisse";
	char sep = ' ';

	char **res = ft_split(str, sep);
	
	printf("RESULT:\n");
	for (int i = 0; i < 13; i++)
		printf("res: '%s'\n", res[i]);
	// free strings
	for (int i = 0; i < 4; i++)
		free(res[i]);
	free(res);
	return 0;
} */
