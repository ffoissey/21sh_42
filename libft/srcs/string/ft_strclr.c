/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:47:43 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:46 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_init(void *s, size_t n)
{
	if (!n)
		return ;
	*((char *)s) = 0;
	while (--n > 0)
		((char *)s)[n] = '\0';
}

static size_t	ft_len(const char *s)
{
	int		i;

	if (*s == '\0')
		return (0);
	i = 0;
	while (s[++i])
		;
	return (i);
}

void			ft_strclr(char *c)
{
	if (!c)
		return ;
	ft_init(c, ft_len(c));
	return ;
}
