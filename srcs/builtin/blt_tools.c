/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:11:41 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:52 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static enum e_state_option	is_option(const char *s)
{
	if (ft_strequ(s, "--") == TRUE)
		return (E_END_OPTION);
	else if (*s == '-' && *(s + 1) != '\0')
		return (E_OPTION);
	return (E_NO_OPTION);
}

t_option					set_options(char ***av, t_get_option get_option)
{
	enum e_state_option	state;
	t_option			option;

	state = E_START_OPTION;
	option = 0;
	if (av == NULL)
		return (option);
	while (**av != NULL)
	{
		state = is_option(**av);
		if (state == E_NO_OPTION)
			return (option);
		else if (state == E_OPTION)
		{
			if ((option = get_option(**av + 1, option)) == ERROR_OPT)
				return (ERROR_OPT);
		}
		(*av)++;
	}
	return (option);
}
