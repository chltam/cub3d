/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:39:45 by cbadura           #+#    #+#             */
/*   Updated: 2022/12/06 12:39:48 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> */

/* Outputs the character ’c’ to the given file
descriptor followed by a newline. */

void	ft_putendl_fd(char *s, int fd)
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
	write(fd, "\n", 1);
}

/* int main(void)
{
	int fd = open("file", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return -1;
	ft_putendl_fd("hello", fd);
	close(fd);
	return 0;
} */
