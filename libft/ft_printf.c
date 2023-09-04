/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:56:40 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/13 15:56:42 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Your function has to handle the following conversions: cspdiuxX%

static void	parse(va_list args, char format, int *sum);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		sum;
	int		i;

	sum = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			parse(args, format[i], &sum);
		}
		else
		{
			ft_putchar(format[i]);
			sum++;
		}
		i++;
	}
	va_end(args);
	return (sum);
}

static void	parse(va_list args, char format, int *sum)
{
	if (format == 'd' || format == 'i')
		*sum += print_int(va_arg(args, int));
	else if (format == 'u')
		*sum += print_unsigned(va_arg(args, unsigned int));
	else if (format == 'c')
		*sum += print_char(va_arg(args, int));
	else if (format == 's')
		*sum += print_string(va_arg(args, char *));
	else if (format == 'x' || format == 'X')
		*sum += print_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		*sum += print_ptr(va_arg(args, void *));
	else if (format == '%')
		*sum += print_percent();
}
