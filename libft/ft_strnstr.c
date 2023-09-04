/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:43:30 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:43:35 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <bsd/string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!to_find || !to_find[i] || str == to_find)
		return ((char *)str);
	if (ft_strlen(to_find) > ft_strlen(str))
		return (NULL);
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (i + j < len && str[i + j] == to_find[j])
			{
				j++;
				if (!to_find[j])
					return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	const char *str = "aaabcabcd";
	const char str2[] = "aabc";

	str = strnstr(str, str2, -1);
	printf("result: %s\n", str);
	str = ft_strnstr(str, str2, -1);
	printf("result: %s\n", str);

	return (0);
} */