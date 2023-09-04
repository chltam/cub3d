/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:41:29 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:41:31 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>
// #include <stdlib.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/* int main()
{
	int c = 'e';
	printf("the letter: %c\n", ft_toupper(c));
	printf("the letter: %c\n", toupper(c));
	return (0);
} */

/* char	*ft_strupcase(char	*str)
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
		if (str[i] >= 'a' && str[i] <= 'z')
			str2[i] = str[i] - 32;
		else
			str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
} */
