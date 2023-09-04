/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:32:09 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:32:13 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* #include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> */

/* Outputs the character ’c’ to the given file
descriptor. */

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd == -1)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/* int main(void)
{
	int fd = open("file", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return -1;
	ft_putstr_fd("hello", fd);
	close(fd);
	return 0;
} */
