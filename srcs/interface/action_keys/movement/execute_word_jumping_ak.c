/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_word_jumping_ak.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:33:40 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:56 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_functions.h"

int8_t		tc_ak_next_word(t_registry *shell)
{
	t_interface		*itf;
	uint32_t		next_char;

	itf = &shell->interface;
	if (validate_interface_content(itf) == FAILURE)
		return (FAILURE);
	if (itf->cursor.index == ft_vctlen(itf->line))
		return (FAILURE);
	else
	{
		next_char = 0;
		next_char = get_next_char(itf->line->buffer, itf->cursor.index, 1);
		while (itf->cursor.index != next_char)
			tc_ak_arrow_right(shell);
	}
	return (SUCCESS);
}

int8_t		tc_ak_prev_word(t_registry *shell)
{
	t_interface		*itf;
	uint32_t		prev_char;

	itf = &shell->interface;
	if (validate_interface_content(itf) == FAILURE)
		return (FAILURE);
	if (itf->cursor.index == 0)
		return (FAILURE);
	else
	{
		prev_char = 0;
		prev_char = get_next_char(itf->line->buffer, itf->cursor.index, -1);
		while (itf->cursor.index != prev_char)
			tc_ak_arrow_left(shell);
	}
	return (SUCCESS);
}

int8_t		tc_ak_ctrl_down(t_registry *shell)
{
	t_interface	*itf;
	uint32_t	prompt_length;
	uint32_t	moves;
	uint32_t	lines_amount;

	itf = &shell->interface;
	if (validate_interface_content(itf) == FAILURE)
		return (FAILURE);
	moves = 0;
	prompt_length = get_prompt_len(shell);
	lines_amount = (((ft_vctlen(itf->line) - 1) + prompt_length)
				/ itf->window.cols) + 1;
	if (lines_amount > 1)
	{
		while (moves < itf->window.cols)
		{
			tc_ak_arrow_right(shell);
			++moves;
		}
	}
	return (SUCCESS);
}

int8_t		tc_ak_ctrl_up(t_registry *shell)
{
	t_interface	*itf;
	uint32_t	moves;
	uint32_t	prompt_length;
	uint32_t	lines_amount;

	itf = &shell->interface;
	if (validate_interface_content(itf) == FAILURE)
		return (FAILURE);
	prompt_length = get_prompt_len(shell);
	lines_amount = (((ft_vctlen(itf->line) - 1) + prompt_length)
			/ itf->window.cols + 1);
	if (itf->cursor.y == 1 && itf->cursor.x <= prompt_length)
		tc_ak_home(shell);
	if (lines_amount > 1 && itf->cursor.y > 0)
	{
		moves = 0;
		while (moves < itf->window.cols)
		{
			tc_ak_arrow_left(shell);
			++moves;
		}
	}
	return (SUCCESS);
}
