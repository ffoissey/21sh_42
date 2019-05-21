/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:30:13 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:44 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	converter(long nb, int fd)
{
	if (nb > 0)
	{
		converter(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long)n;
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	if (nb > 0)
		return (converter(nb, fd));
	ft_putchar_fd('-', fd);
	return (converter(-nb, fd));
}
