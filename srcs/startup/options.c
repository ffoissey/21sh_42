/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:06:27 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:05 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int8_t	shell_option_letter(t_opt *option, char *arg)
{
	if (*arg != '-')
	{
		ft_dprintf(2, "21sh: %c: invalid option\n", *arg);
		return (FAILURE);
	}
	++arg;
	if (*arg == '-')
		return (FAILURE);
	while (*arg != '\0')
	{
		if (*arg == 'h')
			option->option |= HELP_OPT;
		else if (*arg == 'd')
			option->option |= DEBUG_OPT;
		else
		{
			ft_dprintf(2, "21sh: -%c: invalid option\n", *arg);
			return (FAILURE);
		}
		++arg;
	}
	return (SUCCESS);
}

static int8_t	shell_option_word(t_opt *option, const char *arg)
{
	if (ft_strequ(arg, "--help") == TRUE)
		option->option |= HELP_OPT;
	else if (ft_strequ(arg, "--debug") == TRUE)
		option->option |= DEBUG_OPT;
	else
	{
		if (ft_strnequ(arg, "--", 2) == TRUE)
			ft_dprintf(2, "21sh: %s: invalid option\n", arg);
		return (FAILURE);
	}
	return (SUCCESS);
}

int8_t			parse_arg(char **av, t_opt *option)
{
	while (*av != NULL)
	{
		if (ft_strequ(*av, "--") == TRUE)
			return (SUCCESS);
		else if (ft_strequ(*av, "-c") == TRUE)
		{
			option->option |= COMMAND_OPT;
			ft_strdel(&option->command_str);
			av++;
			if (*av == NULL || **av == '-')
			{
				ft_dprintf(2, "21sh: need command after -c option\n", av);
				return (shell_usage());
			}
			option->command_str = ft_strdup(*av);
		}
		else if (shell_option_word(option, *av) == FAILURE)
			if (shell_option_letter(option, *av) == FAILURE)
				return (shell_usage());
		av++;
	}
	return (SUCCESS);
}
