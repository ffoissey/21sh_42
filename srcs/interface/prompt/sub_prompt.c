/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 00:22:47 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:57 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_functions.h"
#include "sh21.h"
#include <unistd.h>

static void			print_sub_prompt(t_registry *shell)
{
	char	*ps;

	ps = get_intern_var(shell, shell->interface.state);
	shell->interface.cursor.x = 0;
	shell->interface.cursor.y = 0;
	ft_putchar('\n');
	if (ps == NULL)
		ps = "sub> ";
	print_words(&shell->interface, ps);
	shell->interface.cursor.index = 0;
}

static int8_t		sub_prompt_loop(t_registry *shell, t_interface *itf)
{
	char		character[READ_SIZE + 1];

	ft_bzero(character, READ_SIZE + 1);
	while (character[0] != IFS_CHAR)
	{
		ft_bzero(character, READ_SIZE);
		if (read(0, character, READ_SIZE) == FAILURE)
		{
			prompt_read_failed(shell, itf->line);
			return (FAILURE);
		}
		handle_input_key(shell, character);
		if (is_eof(itf->line->buffer) == TRUE)
			return (SUCCESS);
	}
	return (SUCCESS);
}

static int8_t		is_std_ps(const char *p_state)
{
	if (ft_strequ(p_state, INT_PS1)
		|| ft_strequ(p_state, INT_PS2)
		|| ft_strequ(p_state, INT_PS3)
		|| ft_strequ(p_state, INT_PS4))
		return (TRUE);
	return (FALSE);
}

void				sub_prompt_error(char **line, t_interface *itf)
{
	*line = NULL;
	reset_vector(itf->line);
	ft_strdel(&(itf->line->buffer));
}

int8_t				invoke_sub_prompt(t_registry *shell, char **line,
						char *prompt_state)
{
	t_interface		*itf;
	char			*old_state;

	old_state = NULL;
	itf = &shell->interface;
	if (prompt_state && is_std_ps(prompt_state) == FALSE)
	{
		add_internal(shell, INT_PS5, prompt_state);
		prompt_state = INT_PS5;
	}
	old_state = itf->state;
	itf->state = prompt_state;
	reset_vector(itf->line);
	if (validate_interface_content(itf) == FAILURE)
		return (FAILURE);
	print_sub_prompt(shell);
	if (sub_prompt_loop(shell, itf) != SUCCESS)
	{
		sub_prompt_error(line, itf);
		return (FAILURE);
	}
	*line = ft_strdup(itf->line->buffer);
	ft_strdel(&(itf->line->buffer));
	itf->state = old_state;
	return (SUCCESS);
}
