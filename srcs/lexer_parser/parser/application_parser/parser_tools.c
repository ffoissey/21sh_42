/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:37:40 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:03 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "unistd.h"

int		is_ionumber(t_parser *parse, char *str)
{
	int		len;

	parse->state = parse->state == P_REDIRECT_AND ? P_DUP_MOVE : P_IO_DUP_MOVE;
	if (ft_strcheck(str, ft_isdigit) == 1)
		return (1);
	len = ft_strlen(str);
	str[len - 1] = character_swap(str[len - 1]);
	if (ft_strcheck(str, ft_isdigit) == 1)
	{
		str[len - 1] = character_swap('\0');
		if (str[len - 1] == '-')
		{
			parse->special_case ^= TO_CLOSE;
			return (1);
		}
	}
	str[len - 1] = character_swap('\0');
	return (0);
}

uint8_t	check_access(char *data)
{
	struct stat	stat;

	if (access(data, F_OK) != SUCCESS)
		return (TRUE);
	lstat(data, &stat);
	if (stat.st_mode & S_IFDIR)
		ft_dprintf(2, "21sh: %s: Is a directory\n", data);
	else if (access(data, R_OK) != SUCCESS)
		ft_dprintf(2, "21sh: %s: Permission denied\n", data);
	else
		return (TRUE);
	return (FALSE);
}

void	check_filename(t_parser *parse)
{
	if (parse->token.data == NULL || check_access(parse->token.data) == FALSE)
	{
		error_parser(parse);
		ft_strdel(&parse->token.data);
	}
	else
		ft_stckpush(&parse->stack, &parse->token, sizeof(t_token));
}
