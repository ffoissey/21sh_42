/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 08:41:50 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:49 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*search(const char *s, int c, int len)
{
	if (c == '\0')
		return ((char *)(s + 1));
	if (len == 0)
		return (NULL);
	return (*s == (char)c ? (char *)s : search(--s, c, --len));
}

char			*ft_strrchr(const char *s, int c)
{
	int		len;

	if (!*s)
		return (*s == (char)c ? (char *)s : NULL);
	len = ft_strlen(s);
	return (search(&s[len - 1], c, len));
}
