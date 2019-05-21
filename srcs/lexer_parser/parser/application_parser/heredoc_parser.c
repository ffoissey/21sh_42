/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:48:28 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:03 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "lexer.h"
#include "parser.h"
#include "interface_functions.h"

static int	write_heredoc(char **line, int fd, t_parser *parse)
{
	int		trim;

	trim = 0;
	if (parse->special_case & HERETRIM)
		trim = ft_strspn(*line, " \t");
	*line = variable_expansion(parse, *line);
	ft_putendl_fd(*line + trim, fd);
	ft_strdel(line);
	return (0);
}

static int	check_delimiter(char **delimiter, char **line, int fd, t_parser *p)
{
	if (ft_strequ(*line, *delimiter) == TRUE || *line[0] == 4)
	{
		close(fd);
		ft_putchar('\n');
		ft_strdel(delimiter);
		ft_strdel(line);
		p->special_case ^= HERETRIM;
		return (SUCCESS);
	}
	write_heredoc(line, fd, p);
	return (FAILURE);
}

void		heredoc_delimiter(t_parser *parse)
{
	if (parse->state == P_HEREDOC_REDIRECT)
		parse->state = P_HEREDOC_DELIMITER;
	else
		parse->state = P_IO_HEREDOC_DELIMITER;
	if (g_shell->is_interactive == FALSE)
	{
		ft_dprintf(2, "21sh: Here documents only in interractive mode\n");
		ft_lstdel(&parse->token_list, del_token);
		ft_strdel(&parse->token.data);
		error_parser(parse);
	}
	parse->token.type = E_STRING;
	ft_stckpush(&parse->stack, &parse->token, sizeof(t_token));
	get_token(parse);
}

void		io_heredoc_parser(t_parser *parse)
{
	char		*line;
	char		*delimiter;
	char		*io;
	int			fd[2];

	parse->state = P_HEREDOC;
	pipe(fd);
	line = NULL;
	delimiter = pop_token_data(&parse->stack);
	pop_token_type(&parse->stack);
	io = pop_token_data(&parse->stack);
	generate_filedesc(parse, fd[0], ft_atoi(io), FD_DUP | FD_WRITE);
	ft_strdel(&io);
	while (invoke_sub_prompt(g_shell, &line, INT_PS4) == SUCCESS)
	{
		if (check_delimiter(&delimiter, &line, fd[1], parse) == SUCCESS)
			return ;
	}
	ft_strdel(&line);
	error_parser(parse);
}

void		heredoc_parser(t_parser *parse)
{
	char		*line;
	char		*delimiter;
	int			fd[2];

	parse->state = P_HEREDOC;
	line = NULL;
	pipe(fd);
	delimiter = pop_token_data(&parse->stack);
	pop_token_data(&parse->stack);
	generate_filedesc(parse, fd[0], STDIN_FILENO, FD_DUP | FD_WRITE);
	while (invoke_sub_prompt(g_shell, &line, INT_PS4) == SUCCESS)
	{
		if (check_delimiter(&delimiter, &line, fd[1], parse) == SUCCESS)
			return ;
	}
	ft_strdel(&line);
	error_parser(parse);
}
