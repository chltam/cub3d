/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:00:59 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/17 15:01:01 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_ptr(unsigned long long hex)
{
	char			*base;

	base = NULL;
	base = ft_strdup("0123456789abcdef");
	if (!base)
		return ;
	if (hex >= 16)
	{
		put_ptr(hex / 16);
		ft_putchar(base[hex % 16]);
	}
	else
		ft_putchar(base[hex]);
	free(base);
}

static int	ptr_len(unsigned long long hex)
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

int	print_ptr(void	*arg)
{
	int		len;
	char	*ptr;

	len = 0;
	ptr = NULL;
	if (arg == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ptr = malloc(12 + 1);
	if (!ptr)
		return (len);
	ptr[12] = '\0';
	ft_putstr("0x");
	put_ptr((unsigned long long) arg);
	len = ptr_len((unsigned long long) arg) + 2;
	free(ptr);
	return (len);
}

int	print_percent(void)
{
	ft_putchar('%');
	return (1);
}
