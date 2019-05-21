/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itf_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:36:52 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:05 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include "interface_functions.h"

void			redraw_prompt(const int signo)
{
	t_interface *itf;

	(void)signo;
	itf = &g_shell->interface;
	tc_ak_end(g_shell);
	if (signo != ft_atoi(INT_MAGIC_NUMBER))
		print_words(itf, "\n");
	itf->cursor.x = 0;
	itf->cursor.y = 0;
	if (signo != ft_atoi(INT_MAGIC_NUMBER))
		ft_vctreset(itf->line);
	itf->hist_ptr = NULL;
	print_words(itf, get_intern_var(g_shell, itf->state));
	itf->cursor.index = 0;
}

void			interface_resize_handler(const int signo)
{
	struct winsize	w;
	t_interface		*itf;

	(void)signo;
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w) == FAILURE)
	{
		ft_dprintf(2, "[ERROR] Terminal size could not be updated.\n");
		return ;
	}
	itf = &g_shell->interface;
	update_window(g_shell);
	tputs(itf->termcaps.clear, 1, ft_putc);
	if ((itf->window.cols
			< (uint32_t)(ft_strlen(get_intern_var(g_shell, INT_PS1)) * 2)
		|| itf->window.rows < 3)
		|| ft_vctlen(itf->line) > (uint32_t)itf->window.max_chars)
		g_shell->interface.allow_input = FALSE;
	else
	{
		g_shell->interface.allow_input = TRUE;
		redraw_prompt(ft_atoi(INT_MAGIC_NUMBER));
		redraw_input_line(g_shell);
		tc_ak_end(g_shell);
	}
}
