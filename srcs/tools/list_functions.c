/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:07:09 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:06 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include <unistd.h>

void	print_filedesc(void *data)
{
	t_filedesc	*fd;

	fd = data;
	if (fd->action & FD_CLOSE)
		ft_printf("Closing FD : %d\n", fd->second);
	else if (fd->action & FD_WRITE)
		ft_printf("FD : %d >>> FD : %d\n", fd->first, fd->second);
	else if (fd->action & FD_READ)
		ft_printf("FD : %d <<< FD : %d\n", fd->first, fd->second);
}

void	print_process(void *data)
{
	t_process	*process;

	process = data;
	ft_putchar('\n');
	ft_showtab(process->av);
	ft_lstiter(process->fd, print_filedesc);
}

int		find_variable(void *data, void *to_find)
{
	t_variable	*variable;
	char		*name;

	name = to_find;
	variable = data;
	return (ft_strequ(variable->name, name));
}

char	*variable_to_str(void *data)
{
	char		*string;
	t_variable	*variable;

	variable = data;
	string = NULL;
	ft_asprintf(&string, "%s=%s", variable->name, variable->data);
	return (string);
}

void	delete_parser(t_parser *parse)
{
	if (parse->tmp_env != NULL)
		ft_lstdel(&parse->tmp_env, NULL);
	if (parse->job_list != NULL)
		ft_lstdel(&parse->job_list, delete_job);
	ft_stckdestroy(&parse->stack, del_token);
}
