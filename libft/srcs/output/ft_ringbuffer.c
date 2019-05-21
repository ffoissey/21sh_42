/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ringbuffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:08:37 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:45 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_ringflush(t_buffer *ring, int fd)
{
	int				output;

	output = ft_putstr_fd(&ring->buffer[ring->index], fd);
	ring->index += output;
	if (ring->index >= BUFF_SIZE - 1)
	{
		ring->index = 0;
		ring->room = BUFF_SIZE - 1;
		ring->buffer[0] = '\0';
	}
	return (output);
}

int				ft_ringbuffer(char *str, int fd)
{
	static t_buffer ring = {.buffer = NULL, .index = 0, .room = BUFF_SIZE - 1};
	size_t			size;
	size_t			diff;

	if (!ring.buffer)
		if (!(ring.buffer = ft_memalloc(BUFF_SIZE)))
			return (-1);
	if (!str)
		return (ft_ringflush(&ring, fd));
	size = ft_strlen(str);
	if (size > ring.room)
	{
		diff = ring.room;
		ft_strncat(&ring.buffer[ring.index], str, ring.room);
		return (ft_ringflush(&ring, fd) + ft_ringbuffer(&str[diff], fd));
	}
	ft_strcat(&ring.buffer[ring.index], str);
	return (!(ring.room -= size) ? ft_ringflush(&ring, fd) : 0);
}
