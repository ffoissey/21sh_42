/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:03:31 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:02 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	number_machine(t_lexer *machine)
{
	if (ft_isdigit(*machine->input) == TRUE)
	{
		machine->last_lexer = E_IO_NUMBER;
		if (create_token_data(machine) == FAILURE)
			return ;
		++machine->input;
	}
	else if (ft_strchr("<>", *machine->input) != NULL)
		machine->state = L_OUT;
	else
	{
		machine->last_lexer = E_STRING;
		machine->state = L_STRING;
	}
}

void	string_special(t_lexer *machine)
{
	machine->last_lexer = E_SPSTRING;
	if (*machine->input == '\"')
		machine->state = L_DQTE;
	else if (*machine->input == '\'')
		machine->state = L_SQTE;
}

void	string_machine(t_lexer *machine)
{
	if (*machine->input == '\0')
		machine->state = L_START;
	if (ft_strchr(LETTER_INTERUPT, *machine->input) != NULL)
	{
		machine->state = L_OUT;
		return ;
	}
	else if (ft_strchr(LETTER_SPECIAL, *machine->input) != NULL)
		string_special(machine);
	else if (machine->last_lexer != E_SPSTRING)
		machine->last_lexer = E_STRING;
	if (*machine->input != '\0')
	{
		if (create_token_data(machine) == FAILURE)
			return ;
		++machine->input;
	}
}
