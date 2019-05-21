/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:57:46 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:03 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "sh21.h"
#include "parser.h"

void	activate_piping(void *data)
{
	t_filedesc *fd;

	fd = data;
	fd->action |= FD_PIPE;
}

void	flush_redirect_and(t_parser *parse)
{
	char			*filedesc;
	int				fd;
	unsigned int	action;
	t_type			type;

	parse->state = P_REDIRECT_FLUSH_AND;
	action = 0;
	filedesc = pop_token_data(&parse->stack);
	fd = ft_atoi(filedesc);
	ft_strdel(&filedesc);
	type = pop_token_type(&parse->stack);
	action |= parse->special_case & TO_CLOSE ? FD_CLOSE : FD_DUP;
	parse->special_case ^= TO_CLOSE;
	if (type == E_LESSAND)
		generate_filedesc(parse, fd, STDIN_FILENO, action | FD_WRITE);
	else
		generate_filedesc(parse, fd, STDOUT_FILENO, action | FD_WRITE);
}

void	flush_redirect(t_parser *parse)
{
	char	*filename;
	t_type	type;
	int		fd;

	parse->state = P_REDIRECT_FLUSH;
	filename = pop_token_data(&parse->stack);
	type = pop_token_type(&parse->stack);
	if ((fd = open(filename, parse->oflags, 0644)) < 0)
	{
		ft_dprintf(2, "21sh: %s: No such file\n", filename);
		error_parser(parse);
	}
	else if (type == E_LESS || type == E_LESSAND)
		generate_filedesc(parse, fd, STDIN_FILENO, FD_DUP | FD_WRITE);
	else
	{
		if (type == E_GREATAND || type == E_ANDDGREAT)
			generate_filedesc(parse, fd, STDERR_FILENO, FD_DUP | FD_WRITE);
		else if (type == E_ANDGREAT)
			generate_filedesc(parse, fd, STDERR_FILENO, FD_DUP | FD_WRITE);
		generate_filedesc(parse, fd, STDOUT_FILENO, FD_DUP | FD_WRITE);
	}
	parse->special_case ^= NO_PIPE;
	ft_strdel(&filename);
}

void	redirect_and_parser(t_parser *parse)
{
	parse->state = P_REDIRECT_AND;
	if (parse->token.type == E_GREATAND)
		parse->oflags = O_RDWR + O_CREAT + O_TRUNC;
	else if (parse->token.type == E_LESSAND)
		parse->oflags = O_RDONLY;
	ft_stckpush(&parse->stack, &parse->token, sizeof(t_token));
	get_token(parse);
}

void	redirect_parser(t_parser *parse)
{
	parse->state = P_REDIRECT;
	if (parse->token.type == E_GREAT)
		parse->oflags = O_RDWR + O_CREAT + O_TRUNC;
	else if (parse->token.type == E_DGREAT || parse->token.type == E_ANDDGREAT)
		parse->oflags = O_RDWR + O_CREAT + O_APPEND;
	else if (parse->token.type == E_LESS)
		parse->oflags = O_RDONLY;
	else if (parse->token.type == E_DLESSDASH || parse->token.type == E_DLESS)
		parse->state = P_HEREDOC_REDIRECT;
	if (parse->token.type == E_DLESSDASH)
		parse->special_case ^= HERETRIM;
	ft_stckpush(&parse->stack, &parse->token, sizeof(t_token));
	get_token(parse);
}
