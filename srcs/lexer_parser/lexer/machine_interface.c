/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:28:28 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:01 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	start_lexer(t_lexer *machine)
{
	if (*machine->input == '\0')
		machine->state = L_END;
	else if (*machine->input == ' ' || *machine->input == '\t')
	{
		machine->io_detect = 0;
		while (*machine->input == ' ' || *machine->input == '\t')
			++machine->input;
	}
	else if (ft_strchr(SIGN_DETECT, *machine->input) != NULL)
		machine->state = L_SIGN;
	else if (ft_isdigit(*machine->input) == TRUE)
		machine->state = L_IO_NUMBER;
	else
		machine->state = L_STRING;
}

void	end_machine(t_lexer *machine)
{
	if (*machine->buffer != '\0')
		machine->state = L_OUT;
	else if (machine->last_lexer != E_END)
	{
		machine->last_lexer = E_END;
		machine->state = L_OUT;
	}
	else
		machine->state = L_FINISH;
}

void	out_lexer(t_lexer *machine)
{
	t_list	*node;
	t_token	token;

	token = generate_token(machine);
	if ((node = ft_lstnew(&token, sizeof(token))) == NULL)
		return ;
	ft_lstaddback(&machine->tokens, node);
	machine->state = L_START;
}
