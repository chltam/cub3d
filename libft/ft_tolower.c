/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:41:59 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:42:01 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>
// #include <stdlib.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/* int main()
{
	int c = 'E';
	printf("the letter: %c\n", ft_tolower(c));
	printf("the letter: %c\n", tolower(c));
	return (0);
} */

/* char	*ft_strlowcase(char	*str)
{
	char	*str2;
	int		i;
	int		len;

	len = ft_strlen(str);
	str2 = malloc(sizeof(char) * len + 1);
	i = 0;
	if (str[i] == '\0')
		return ("");
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str2[i] = str[i] + 32;
		else
			str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
} */
