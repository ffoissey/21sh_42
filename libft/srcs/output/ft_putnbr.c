/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:26:51 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:44 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	converter(long nb)
{
	if (nb > 0)
	{
		converter(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

void			ft_putnbr(int n)
{
	long	nb;

	nb = (long)n;
	if (n == 0)
		return (ft_putchar('0'));
	if (nb > 0)
		return (converter(nb));
	ft_putchar('-');
	return (converter(-nb));
}
