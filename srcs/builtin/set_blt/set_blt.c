/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_blt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:23:09 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:54 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int8_t				set_blt(t_registry *shell, char **av)
{
	(void)av;
	print_lst(&shell->intern, shell->cur_fd.out);
	return (SUCCESS);
}
