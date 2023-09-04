/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:39:31 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:39:36 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* #include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> */

/* Outputs the character ’c’ to the given file
descriptor. */

void	ft_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return ;
	write(fd, &c, 1);
}

/* int main(void)
{
	int fd = open("file", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return -1;
	ft_putchar_fd('A', fd);
	close(fd);
	return 0;
} */
