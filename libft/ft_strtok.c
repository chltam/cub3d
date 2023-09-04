/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:08:15 by htam              #+#    #+#             */
/*   Updated: 2023/03/28 21:09:01 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, char *delim)
{
	static char	*stash;
	char		*restr;
	int			n;

	n = 0;
	if (str)
		stash = str;
	if (stash == NULL)
		return (NULL);
	while (*stash)
	{
		n = 0;
		if (!ft_strchr(delim, *stash))
		{
			while (stash[n] && !ft_strchr(delim, stash[n]))
				n++;
			restr = ft_substr(stash, 0, n);
			stash += n;
			return (restr);
		}
		stash++;
	}
	restr = NULL;
	return (restr);
}
