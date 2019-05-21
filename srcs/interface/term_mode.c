/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:05:30 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:58 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include <termios.h>
#include <unistd.h>

int8_t			set_term_behavior(t_registry *shell)
{
	struct termios	term;

	if ((tcgetattr(STDIN_FILENO, &term)) == FAILURE)
	{
		log_print(shell, LOG_ERROR, "Tcgetattr failed fetching info.\n");
		return (FAILURE);
	}
	if ((shell->interface.orig_mode = ft_memalloc(sizeof(struct termios)))
					== NULL)
		return (FAILURE);
	ft_memcpy(shell->interface.orig_mode, &term, sizeof(struct termios));
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if ((shell->interface.term_mode = ft_memalloc(sizeof(struct termios)))
					== NULL)
		return (FAILURE);
	ft_memcpy(shell->interface.term_mode, &term, sizeof(struct termios));
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == FAILURE)
	{
		log_print(shell, LOG_ERROR, "Tcsetattr failed setting params.\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int8_t			restore_term_behavior(t_registry *shell)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, shell->interface.orig_mode) == FAILURE)
	{
		log_print(shell, LOG_ERROR, "Tcsetattr failed setting params.\n");
		return (FAILURE);
	}
	ft_free(shell->interface.term_mode);
	ft_free(shell->interface.orig_mode);
	return (SUCCESS);
}
