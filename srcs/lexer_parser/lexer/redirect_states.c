/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_states.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:23:05 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:01 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lesser_machine(t_lexer *machine)
{
	uint32_t	checker;

	checker = 0;
	if (machine->last_lexer == E_DLESS && *machine->input == '-' && ++checker)
		machine->last_lexer = E_DLESSDASH;
	else if (*machine->buffer == '<' && *machine->input == '<')
	{
		if (machine->last_lexer != E_DLESS)
		{
			machine->last_lexer = E_DLESS;
			if (create_token_data(machine) != FAILURE)
				++machine->input;
			return ;
		}
	}
	else if (*machine->input == '>' || *machine->input == '&')
	{
		if (*machine->buffer == '<' && *machine->input == '&' && ++checker)
			machine->state = L_LESSAND;
		else if (*machine->buffer == '<' && *machine->input == '>' && ++checker)
			machine->last_lexer = E_LESSGREAT;
	}
	if (checker != FALSE)
		++machine->input;
	machine->state = machine->state == L_LESSAND ? L_LESSAND : L_OUT;
}

void	greater_machine(t_lexer *machine)
{
	uint32_t	checker;

	checker = 0;
	if (ft_strchr(">&|", *machine->input) != NULL)
	{
		if (*machine->buffer == '>' && *machine->input == '>' && ++checker)
			machine->last_lexer = E_DGREAT;
		else if (*machine->buffer == '>' && *machine->input == '&' && ++checker)
			machine->state = L_GREATAND;
		else if (*machine->buffer == '>' && *machine->input == '|' && ++checker)
			machine->last_lexer = E_CLOBBER;
	}
	if (checker != FALSE)
		++machine->input;
	machine->state = machine->state == L_GREATAND ? L_GREATAND : L_OUT;
}

void	greatand_machine(t_lexer *machine)
{
	machine->last_lexer = E_GREATAND;
	*machine->buffer = '\0';
	machine->state = L_OUT;
}

void	lessand_machine(t_lexer *machine)
{
	machine->last_lexer = E_LESSAND;
	*machine->buffer = '\0';
	machine->state = L_OUT;
}
