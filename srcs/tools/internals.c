/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:15:49 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:06 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char		*get_intern_var(t_registry *shell, char *name)
{
	return (get_data(shell->intern, name));
}

int8_t		add_internal(t_registry *shell, char *name, char *data)
{
	if (get_data(shell->intern, name) == NULL)
		return (s_create_node(&(shell->intern), name, data));
	return (change_node(&(shell->intern), name, ft_strdup(data)));
}

char		*get_env_var(t_registry *shell, char *name)
{
	return (get_data(shell->env, name));
}

int8_t		add_env(t_registry *shell, char *name, char *data)
{
	if (get_data(shell->env, name) == NULL)
		return (s_create_node(&(shell->env), name, data));
	return (change_node(&(shell->env), name, ft_strdup(data)));
}

int8_t		add_internal_nbr(t_registry *shell, char *name, int data)
{
	int8_t	ret;
	char	*data_copy;

	ret = SUCCESS;
	data_copy = NULL;
	data_copy = ft_itoa(data);
	ret = add_internal(shell, name, data_copy);
	ft_strdel(&data_copy);
	return (ret);
}
