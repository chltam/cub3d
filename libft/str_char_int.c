/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_char_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:18:09 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/17 14:18:12 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_uint(unsigned int n);

int	print_string(char *str)
{
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int	print_char(char c)
{
	ft_putchar(c);
	return (1);
}

int	print_int(int n)
{
	int	len;
	int	n_cpy;

	n_cpy = n;
	len = 0;
	if (n == 0)
		len++;
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	ft_putnbr(n_cpy);
	return (len);
}

int	print_unsigned(unsigned int arg)
{
	int	len;

	if ((int)arg < 0)
		len = put_uint(UINT_MAX + arg + 1);
	else
		len = put_uint(arg);
	return (len);
}

static int	put_uint(unsigned int n)
{
	int				len;
	unsigned int	n_cpy;

	n_cpy = n;
	len = 0;
	if (n > UINT_MAX)
		return (len);
	if (n == 0)
		len++;
	while (n_cpy)
	{
		n_cpy /= 10;
		len++;
	}
	if (n >= 10)
	{
		put_uint(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
	return (len);
}
