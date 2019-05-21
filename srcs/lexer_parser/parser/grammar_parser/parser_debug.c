/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:42:18 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:04 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_registry	*g_shell;

void		print_token_debug(t_token *token)
{
	ft_printf("\033[37m         --------\n         |   ");
	if (token->type == E_STRING || token->type == E_SPSTRING)
		ft_printf("%5s   | data [%s]\n         --------\033[0m\n",
				g_shell->grammar[token->type], token->data);
	else
		ft_printf("%c   |\n         --------\033[0m\n",
				g_shell->grammar[token->type]);
}

void		print_arrow_debug(int which)
{
	if (which == 0)
		ft_printf("\033[33m            ||\n            ||\n");
	else if (which == 1)
		ft_printf("\033[34m            ||\n            up\n            ||");
	else
		ft_printf("\033[36m            ||\n           down\n            ||");
	ft_printf("            vv\n\033[0m");
}

void		print_error_debug(enum e_type type, int which)
{
	if (which == 0)
		ft_printf("\033[31m ==> ERROR: token type %d is not possible\n\033[0m",
				type);
	else if (which == 1)
		ft_printf("\033[31m ==> ERROR: miss token type %d\n\033[0m", type);
	else
		ft_printf("\033[31m ==> ERROR: parsing error\n\033[0m");
}

void		print_result_debug(int which)
{
	ft_printf("\033[32m         --------\n         |  ");
	if (which == 0)
		ft_printf("OK");
	else
		ft_printf("KO");
	ft_printf("  |\n         --------\n\n\033[0m");
}
