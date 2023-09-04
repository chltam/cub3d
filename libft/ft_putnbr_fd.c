/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:31:51 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:32:03 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> */

/* Outputs the character ’c’ to the given file
descriptor. */

void	ft_putnbr_fd(int n, int fd)
{
	if (fd == -1)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

/* int main(void)
{
	int fd = open("file", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return -1;
	ft_putnbr_fd(-2147483648, fd);
	close(fd);
	return 0;
} */
