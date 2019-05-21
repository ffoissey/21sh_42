/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_states.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:34:28 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:01 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	single_quote_machine(t_lexer *machine)
{
	if (*machine->input == '\0')
	{
		machine->state = L_OUT;
		return ;
	}
	if (*machine->input == '\'')
		machine->state = L_STRING;
	if (*machine->input != '\0')
	{
		if (create_token_data(machine) == FAILURE)
			return ;
		++machine->input;
	}
	else
		machine->state = L_START;
}

void	double_quote_machine(t_lexer *machine)
{
	if (*machine->input == '\0')
	{
		machine->state = L_OUT;
		return ;
	}
	if (*machine->input == '\"')
		machine->state = L_STRING;
	if (*machine->input != '\0')
	{
		if (create_token_data(machine) == FAILURE)
			return ;
		++machine->input;
	}
	else
		machine->state = L_START;
}
