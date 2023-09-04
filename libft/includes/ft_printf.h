/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:57:24 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/13 15:57:26 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		print_int(int arg);
int		print_unsigned(unsigned int arg);
int		print_string(char *arg);
int		print_char(char arg);
int		print_hex(unsigned int hex, char mode);
int		print_ptr(void *arg);
int		print_percent(void);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strcpy(char *dst, const char *src);
void	ft_putchar(int c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);

#endif
