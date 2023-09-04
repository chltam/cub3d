/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_ptr_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:18:39 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/17 14:18:42 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int hex)
{
	int	len;

	len = 0;
	while (hex)
	{
		hex /= 16;
		len++;
	}
	return (len);
}

static void	put_hex(unsigned int hex, char mode)
{
	char			*base;

	base = NULL;
	if (mode == 'x')
		base = ft_strdup("0123456789abcdef");
	else if (mode == 'X')
		base = ft_strdup("0123456789ABCDEF");
	if (!base)
		return ;
	if (hex >= 16)
	{
		put_hex(hex / 16, mode);
		ft_putchar(base[hex % 16]);
	}
	else
		ft_putchar(base[hex]);
	free(base);
}

int	print_hex(unsigned int hex, char mode)
{
	int				len;

	len = 0;
	if (hex == 0)
	{
		ft_putchar('0');
		return (1);
	}
	put_hex(hex, mode);
	len = hex_len(hex);
	return (len);
}
