/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedricmpassi <ffoissey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:42:54 by cedricmpa         #+#    #+#             */
/*   Updated: 2019/05/07 21:00:23 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

typedef struct		s_buffer
{
	char			*buffer;
	unsigned int	index;
	unsigned int	room;
}					t_buffer;

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr(char const *str);
void				ft_putnstr(char *str, size_t n);
int					ft_putstr_fd(char const *str, int fd);
int					ft_ringbuffer(char *str, int fd);
#endif
