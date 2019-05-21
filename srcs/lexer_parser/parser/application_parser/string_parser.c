/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:17:49 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:03 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	flush_string(t_parser *parse)
{
	int		index;
	t_token *token;

	parse->state = P_STRING_FLUSH;
	if (ft_stcksize(&parse->stack) == 0)
		return ;
	index = ft_stcksize(&parse->stack);
	parse->process.av = (char **)ft_malloc(sizeof(char *) * (index + 1));
	if (parse->process.av == NULL)
		return ;
	parse->process.av[index] = NULL;
	while (--index >= 0)
	{
		token = ft_stckpop(&parse->stack);
		parse->process.av[index] = token->data;
		ft_free(token);
	}
	parse->special_case ^= VALID_PROCESS;
}

void	special_string_parser(t_parser *parse)
{
	parse->state = P_SPSTRING;
	parse->token.type = E_STRING;
	if ((parse->token.data = string_expansion(parse, parse->token.data)))
		ft_stckpush(&parse->stack, &parse->token, sizeof(t_token));
	get_token(parse);
}

void	string_parser(t_parser *parse)
{
	parse->state = P_STRING;
	ft_stckpush(&parse->stack, &parse->token, sizeof(t_token));
	get_token(parse);
}
