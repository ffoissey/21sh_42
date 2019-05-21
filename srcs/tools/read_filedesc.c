/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_filedesc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:19:49 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:06 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strjoinfree(char *s1, const char *s2, const short todel)
{
	char	*join;

	if ((join = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	if (todel == 1)
		ft_strdel(&s1);
	return (join);
}

char	*read_input(const int fd)
{
	char	*final;
	char	buffer[16];

	final = NULL;
	ft_memset(buffer, 0, 16);
	while (read(fd, buffer, 15) > 0)
	{
		if (final == NULL)
			final = ft_strdup(buffer);
		else
			final = ft_strjoinfree(final, buffer, 1);
		ft_memset(buffer, 0, 16);
	}
	return (final);
}
