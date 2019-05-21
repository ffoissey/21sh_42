/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:57:46 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:12:14 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include <fcntl.h>
#include <unistd.h>
#include "parser.h"

void	pipe_parser(t_parser *parse)
{
	t_list		*node;
	int			fd[2];

	parse->state = pipe(fd) ? P_ERROR : P_PIPE;
	parse->special_case ^= VALID_PROCESS;
	if (parse->state == P_ERROR)
		return ;
	if (parse->special_case & NO_PIPE)
		close(fd[1]);
	else
	{
		generate_filedesc(parse, STDIN_FILENO, fd[0], FD_CLOSE);
		generate_filedesc(parse, fd[1], STDOUT_FILENO
				, FD_DUP | FD_WRITE | FD_PIPE);
	}
	node = ft_lstnew(&parse->process, sizeof(t_process));
	ft_lstaddback(&parse->job.process_list, node);
	init_process(&parse->process);
	generate_filedesc(parse, STDOUT_FILENO, fd[1], FD_CLOSE);
	generate_filedesc(parse, fd[0], STDIN_FILENO, FD_DUP | FD_WRITE | FD_PIPE);
	get_token(parse);
}
