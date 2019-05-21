/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 22:18:22 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:04 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "lexer.h"

void		lexer_print_debug(t_registry *shell, t_list *token_list)
{
	if ((shell->option.option & DEBUG_OPT) != FALSE)
	{
		ft_putendl("\n\033[34m-------------- LEXER ---------------");
		ft_lstiter(token_list, print_token);
		ft_putendl("------------------------------------\033[0m");
	}
}

void		parser_print_debug(t_registry *shell, t_parser *parse)
{
	if ((shell->option.option & DEBUG_OPT) != FALSE)
	{
		ft_putstr("\n\033[33m-------------- PARSER --------------");
		if (parse->valid == 1)
			ft_lstiter(((t_job *)(parse->job_list->data))->process_list,
					print_process);
		else
			ft_putstr(NULL);
		ft_putendl("------------------------------------\033[0m\n");
	}
}
