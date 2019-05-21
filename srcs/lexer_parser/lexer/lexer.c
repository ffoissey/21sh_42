/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:23:19 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:01 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "struct.h"
#include "libft.h"
#include <stdlib.h>

int				create_token_data(t_lexer *machine)
{
	if (machine->buffer_index == BUFFER)
	{
		ft_dprintf(2, "21sh: Argument too long\n");
		ft_lstdel(&machine->tokens, del_token);
		machine->state = L_FINISH;
		machine->tokens = NULL;
		return (FAILURE);
	}
	machine->buffer[machine->buffer_index++] = *machine->input;
	return (SUCCESS);
}

t_list			*lexer(t_lexinfo *info, char *input)
{
	t_lexer	machine;

	if (input == NULL)
		return (NULL);
	while (*input == '\t' || *input == ' ')
		input++;
	if (*input == '\0')
		return (NULL);
	ft_bzero(&machine, sizeof(t_lexer));
	machine.state = L_START;
	machine.last_lexer = E_DEFAULT;
	machine.input = input;
	machine.lexinfo = info;
	while (machine.state != L_FINISH)
		machine.lexinfo->lexing[machine.state](&machine);
	return (machine.tokens);
}
