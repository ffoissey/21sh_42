/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:49:05 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:57 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_functions.h"
#include <termcap.h>
#include <unistd.h>

void	print_char(t_interface *itf, const char d)
{
	write(1, &d, 1);
	itf->cursor.index++;
	itf->cursor.x++;
	if (itf->cursor.x == itf->window.cols)
	{
		tputs(itf->termcaps.cs_down, 1, &ft_putc);
		itf->cursor.x = 0;
		itf->cursor.y++;
	}
}

void	print_words(t_interface *itf, const char *str)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
		print_char(itf, str[i++]);
}
