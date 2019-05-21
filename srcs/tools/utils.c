/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:06:50 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:11 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void			print_lst(t_list **alst, int fd)
{
	t_list *ptr;

	if (alst == NULL)
		return ;
	ptr = *alst;
	while (ptr != NULL)
	{
		ft_dprintf(fd, "%s=%s\n", ((t_variable *)ptr->data)->name
				, ((t_variable *)ptr->data)->data, ptr->next);
		ptr = ptr->next;
	}
}

int8_t			f_create_node(t_list **alst, const char *str)
{
	t_variable	variable;
	t_list		*newdir;

	if (str == NULL)
		return (FAILURE);
	ft_bzero(&variable, sizeof(t_variable));
	variable.name = ft_strsub(str, 0, ft_strcspn(str, "="));
	variable.data = ft_strdup(str + (ft_strcspn(str, "=") + 1));
	if (variable.name == NULL || variable.data == NULL)
		return (FAILURE);
	if ((newdir = ft_lstnew(&variable, sizeof(t_variable))) == NULL)
		return (FAILURE);
	ft_lstaddback(alst, newdir);
	return (SUCCESS);
}

int8_t			s_create_node(t_list **alst, const char *name, const char *data)
{
	t_variable	variable;
	t_list		*newdir;

	if (name == NULL)
		return (FAILURE);
	ft_bzero(&variable, sizeof(t_variable));
	variable.name = ft_strdup(name);
	variable.data = ft_strdup(data);
	if (variable.name == NULL || variable.data == NULL)
		return (FAILURE);
	if ((newdir = ft_lstnew(&variable, sizeof(t_variable))) == NULL)
		return (FAILURE);
	ft_lstaddback(alst, newdir);
	return (SUCCESS);
}

int8_t			change_node(t_list **alst, const char *name, char *data)
{
	t_list *ptr;

	ptr = *alst;
	if (name == NULL || data == NULL)
		return (FAILURE);
	while (ptr != NULL)
	{
		if (ft_strequ(((t_variable *)ptr->data)->name, name) == TRUE)
		{
			ft_free(((t_variable *)ptr->data)->data);
			((t_variable *)ptr->data)->data = data;
			return (SUCCESS);
		}
		ptr = ptr->next;
	}
	return (s_create_node(alst, name, data));
}

char			*get_data(t_list *lst, char *name)
{
	t_list *node;

	if ((node = ft_lstfind(lst, name, find_variable)))
		return (((t_variable *)node->data)->data);
	return (NULL);
}
