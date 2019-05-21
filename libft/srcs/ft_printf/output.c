/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:37:04 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:31 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int		format_to_str(const char **format, char **dst)
{
	char			*tmp;
	char			*holder;
	size_t			index;

	index = ft_strcspn(*format, "%");
	if (!(tmp = ft_strsub(*format, 0, index)))
		return (-1);
	if (!(holder = ft_strjoin(*dst, tmp)))
	{
		ft_strdel(&tmp);
		return (-1);
	}
	ft_strdel(&tmp);
	ft_strdel(dst);
	*dst = holder;
	*format += index;
	return (1);
}

int				soutput(char **dst, const char *fmt, t_list *node)
{
	t_format		*tmp;
	char			*holder;
	char			*s;

	if (!*fmt)
		return (ft_strlen(*dst));
	if (*fmt == '%')
	{
		tmp = (t_format *)(node->data);
		tmp->convert(tmp);
		s = tmp->output;
		if (!(holder = ft_strjoin(*dst, s)))
			return (-1);
		ft_strdel(dst);
		*dst = holder;
		return (soutput(dst, fmt + tmp->diff, node->next));
	}
	if (format_to_str(&fmt, dst) == -1)
		return (-1);
	return (soutput(dst, fmt, node));
}

static int		format_to_fd(const char **format, int fd)
{
	int				result;
	char			*tmp;
	size_t			index;

	index = ft_strcspn(*format, "%");
	tmp = ft_strsub(*format, 0, index);
	result = ft_ringbuffer(tmp, fd);
	ft_strdel(&tmp);
	*format += index;
	return (result);
}

int				doutput(const char *fmt, t_list *node, int fd)
{
	t_format		*tmp;

	if (!*fmt)
		return (ft_ringbuffer(NULL, fd));
	if (*fmt == '%')
	{
		tmp = (t_format *)(node->data);
		if (tmp->valid)
			tmp->convert(tmp);
		if (tmp->type == 'c' && tmp->arg.character == 0 && tmp->valid)
		{
			return (ft_ringbuffer(tmp->output, fd) + ft_ringbuffer(NULL, fd)
					+ write(fd, "", 1)
					+ doutput(fmt + tmp->diff, node->next, fd));
		}
		return (ft_ringbuffer(tmp->output, fd) - tmp->color_len
				+ doutput(fmt + tmp->diff, node->next, fd));
	}
	return (format_to_fd(&fmt, fd) + doutput(fmt, node, fd));
}
