/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 22:07:09 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:06 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>

void	close_fd(void *data)
{
	t_filedesc		*fd;

	fd = data;
	if (fd->first > 2)
		close(fd->first);
	if (fd->second > 2)
		close(fd->second);
}

void	del_token(void *token)
{
	t_token *tmp;

	tmp = token;
	ft_strdel(&tmp->data);
}

void	delete_variable(void *data)
{
	t_variable *variable;

	variable = data;
	if (variable->data)
		ft_strdel(&variable->data);
}

void	delete_process(void *data)
{
	t_process	*process;

	process = (t_process *)data;
	ft_freetab(&process->av);
	ft_lstdel(&process->fd, close_fd);
}

void	delete_job(void *data)
{
	t_job	*job;

	job = (t_job *)data;
	ft_lstdel(&job->process_list, delete_process);
}
