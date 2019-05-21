/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_registry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:03:36 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:58 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_functions.h"

void	cleanup_interface(t_registry *shell)
{
	update_window(shell);
	ft_vctreset(shell->interface.line);
	shell->interface.cursor.x = get_prompt_len(shell);
	shell->interface.cursor.y = 0;
	shell->interface.cursor.index = 0;
}

void	unload_interface(t_interface *itf)
{
	t_history	*del;
	t_history	*ptr;

	ptr = itf->history_head;
	while (ptr != NULL)
	{
		ft_strdel(&(ptr->command));
		del = ptr->next;
		ft_free(ptr);
		ptr = del;
	}
	ft_strdel(&(itf->current_line));
	ft_strdel(&(itf->clip->buffer));
	ft_strdel(&(itf->line->buffer));
	ft_free(itf->clip);
	ft_free(itf->line);
	ft_strdel(&(itf->termcaps.clear));
	ft_strdel(&(itf->termcaps.cs_down));
	ft_strdel(&(itf->termcaps.cs_up));
	ft_strdel(&(itf->termcaps.cs_right));
	ft_strdel(&(itf->termcaps.cs_left));
}
