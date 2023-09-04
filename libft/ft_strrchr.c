/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:43:06 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:43:08 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	if (c == '\0')
		return ((char *)str + len);
	if (str[0] == '\0')
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		i++;
		str++;
	}
	i = 0;
	while (i < len)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str--;
		i++;
	}
	return (NULL);
}

	/* if (*str == '\0')
		return ((char *)str); */
/* int main()
{
    char str[8]  = "";
    char letter = 'V';
	char *empty = (char*)calloc(1, 1);
    
	printf("strrchr -> '%s'\n", strrchr(str, letter));
    printf("ft_strrchr -> '%s'\n", ft_strrchr(str, letter));

	printf("strrchr -> '%s'\n", strrchr(empty, letter));
    printf("ft_strrchr -> '%s'\n", ft_strrchr(empty, letter));
    return 0;
} */