/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 09:42:16 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:56 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static char		*apply_history_filter(const char *command)
{
	char	*ptr;
	char	*new;

	if ((new = ft_strdup(command)) == NULL)
		return (NULL);
	ptr = new;
	while (*ptr != '\0')
	{
		if (*ptr == IFS_CHAR)
			*ptr = ' ';
		++ptr;
	}
	return (new);
}

void			push_history_entry(t_history **head, t_history *node)
{
	t_history *hist_ptr;

	if (node == NULL)
		return ;
	if (head == NULL || *head == NULL)
		*head = node;
	else
	{
		hist_ptr = *head;
		while (hist_ptr->prev != NULL)
			hist_ptr = hist_ptr->prev;
		hist_ptr->prev = node;
		node->next = hist_ptr;
		*head = node;
	}
}

t_history		*create_history_entry(const char *command)
{
	t_history	*new;

	new = NULL;
	if ((new = ft_malloc(sizeof(t_history))) == NULL)
		return (NULL);
	new->command = apply_history_filter(command);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
