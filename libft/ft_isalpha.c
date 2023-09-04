/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:35:56 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:36:05 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

static int	check_downcase(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

static int	check_upcase(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (!check_downcase(c) && !check_upcase(c))
		return (0);
	else
		return (1);
}

/* int main()
{
	char c = '2';
	
	printf("it's alpha? - %d\n", ft_isalpha(c));
	return (0);
} */

/* int	ft_str_is_alpha(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!check_downcase(str[i]) && !check_upcase(str[i]))
			return (0);
		i++;
	}
	return (1);
} */
