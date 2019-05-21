/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:07:06 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:50 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "ft_malloc.h"

static int	parser(char const *s, char *c)
{
	while (ft_strchr(c, *s) && *s)
		s++;
	if (*s == '\0')
		return (0);
	while (!ft_strchr(c, *s) && *s)
		s++;
	return (1 + parser(s, c));
}

static int	writer(char const *s, char *c, char ***tab, int word)
{
	int		i;

	i = 0;
	while (ft_strchr(c, *s) && *s)
		s++;
	if (*s == '\0')
		return (1);
	while (!ft_strchr(c, s[i]) && s[i])
		i++;
	if (!(tab[0][word] = (char *)ft_malloc(sizeof(char) * i + 1)))
		return (-1);
	ft_strncpy(tab[0][word], s, i);
	tab[0][word][i] = '\0';
	if (writer(s + i, c, tab, word + 1) == 1)
		return (1);
	else
		ft_strdel(&tab[0][word]);
	return (-1);
}

char		**ft_strsplit(char const *s, char *c)
{
	char	**tab;
	int		wordnum;

	if (!s || !(wordnum = parser(s, c)))
		return (NULL);
	if (!(tab = (char **)ft_malloc(sizeof(char *) * (wordnum + 1))))
		return (NULL);
	if (writer(s, c, &tab, 0) == -1)
		return (NULL);
	tab[wordnum] = NULL;
	return (tab);
}