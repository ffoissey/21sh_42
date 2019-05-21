/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 04:47:14 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:02 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "unistd.h"

void	filename_parser(t_parser *parse)
{
	if (parse->token.type == E_SPSTRING)
		parse->token.data = string_expansion(parse, parse->token.data);
	if (parse->state == P_IO_REDIRECT)
		parse->state = P_IO_FILENAME;
	else if (parse->token.type == E_SPSTRING)
		parse->state = P_SPFILENAME;
	else
		parse->state = P_FILENAME;
	check_filename(parse);
	get_token(parse);
}

void	dup_move_parser(t_parser *parse)
{
	t_token *token;

	if ((parse->token.data = string_expansion(parse, parse->token.data)))
	{
		if (is_ionumber(parse, parse->token.data))
			ft_stckpush(&parse->stack, &parse->token, sizeof(t_token));
		else if ((token = ft_stcktop(&parse->stack))->type == E_LESSAND)
		{
			ft_dprintf(2, "21sh: %s: ambigous redirect", parse->token.data);
			error_parser(parse);
		}
		else
		{
			parse->state = P_FILENAME;
			ft_stckpush(&parse->stack, &parse->token, sizeof(t_token));
		}
		get_token(parse);
	}
	else
	{
		ft_strdel(&parse->token.data);
		error_parser(parse);
	}
}

void	io_dup_move_parser(t_parser *parse)
{
	parse->token.type = E_STRING;
	if ((parse->token.data = string_expansion(parse, parse->token.data)))
	{
		if (is_ionumber(parse, parse->token.data))
			ft_stckpush(&parse->stack, &parse->token, sizeof(t_token));
		else
		{
			error_parser(parse);
			ft_strdel(&parse->token.data);
		}
		get_token(parse);
	}
	else
	{
		ft_strdel(&parse->token.data);
		error_parser(parse);
	}
}
