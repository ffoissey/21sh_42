/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:28:43 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:31 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		ft_vdprintf(const char *format, va_list args, int fd)
{
	t_list			*lst;
	int				result;

	lst = format_list(format, args);
	result = doutput(format, lst, fd);
	ft_lstdel(&lst, format_delete);
	return (result);
}

int		ft_vasprintf(char **dst, const char *format, va_list args)
{
	t_list			*lst;
	int				result;

	if (!(lst = format_list(format, args)))
		return (-1);
	result = soutput(dst, format, lst);
	ft_lstdel(&lst, format_delete);
	return (result);
}

int		ft_asprintf(char **dst, const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_vasprintf(dst, format, args);
	va_end(args);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_vdprintf(format, args, 1);
	va_end(args);
	return (result);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		result;

	if (fd < 0)
		return (-1);
	va_start(args, format);
	result = ft_vdprintf(format, args, fd);
	va_end(args);
	return (result);
}
