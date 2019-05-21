/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_blt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:11:50 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/21 18:30:53 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "sh21.h"
#include <unistd.h>
#include <limits.h>

static char			*ft_get_curpath(t_registry *shell,
							const char *path_give_by_user)
{
	char	*home_path;
	char	*curpath;

	if (path_give_by_user == NULL)
	{
		home_path = get_env_var(shell, "HOME");
		curpath = ft_strdup(home_path != NULL ? home_path : get_home_path());
	}
	else if (ft_strequ(path_give_by_user, "-") == TRUE)
	{
		if ((curpath = get_env_var(shell, "OLDPWD")) == NULL)
			ft_dprintf(shell->cur_fd.err, CD_ERROR_OLDPWD_NOTSET);
		else
			curpath = ft_strdup(curpath);
	}
	else if (*path_give_by_user == '/' || *path_give_by_user == '.')
		curpath = ft_strdup(path_give_by_user);
	else
	{
		if ((curpath = is_cdpath_env(shell, path_give_by_user)) == NULL)
			curpath = ft_strdup(path_give_by_user);
	}
	return (curpath);
}

static void			set_oldpwd_and_pwd(t_registry *shell, char *curpath,
						char *old_pwd, const t_option option)
{
	char		*pwd;

	if (option & P_OPT)
	{
		pwd = NULL;
		pwd = getcwd(NULL, PATH_MAX);
		add_env(shell, "PWD", pwd);
		ft_strdel(&pwd);
	}
	else
		add_env(shell, "PWD", curpath);
	add_env(shell, "OLDPWD", old_pwd);
}

static int8_t		change_directory(t_registry *shell, char *curpath,
						const char *path_give_by_user, const t_option option)
{
	char		*old_pwd;

	old_pwd = get_pwd(shell, NO_OPT);
	if (check_path(shell, curpath, path_give_by_user) == TRUE)
	{
		set_oldpwd_and_pwd(shell, curpath, old_pwd, option);
		if (ft_strequ(path_give_by_user, "-") == TRUE)
			ft_dprintf(shell->cur_fd.out, "%s\n", get_env_var(shell, "PWD"));
		return (exit_cd(shell, &old_pwd, &curpath, SUCCESS));
	}
	return (exit_cd(shell, &old_pwd, &curpath, FAILURE));
}

static int8_t		is_root(char *path)
{
	uint32_t	i;

	i = 0;
	if (path == NULL || path[0] == '\0')
		return (FALSE);
	while (path[i] != '\0')
	{
		if (path[i] != '/')
			return (FALSE);
		++i;
	}
	path[1] = '\0';
	return (TRUE);
}

int8_t				cd_blt(t_registry *shell, char **av)
{
	char		*curpath;
	t_option	option;

	av++;
	if (((option = set_options(&av, get_option_cd)) == ERROR_OPT)
		|| (curpath = ft_get_curpath(shell, *av)) == NULL
		|| one_only_arg(shell, av) == FALSE)
		return (FAILURE);
	if (is_root(curpath) == FALSE && curpath[ft_strlen(curpath) - 1] == '/')
		curpath[ft_strlen(curpath) - 1] = '\0';
	if ((option & P_OPT) == FALSE)
	{
		if (*curpath != '/')
			if ((curpath = concat_pwd_with_curpath(shell, &curpath)) == NULL)
				return (FAILURE);
		if ((curpath = make_curpath_simple(curpath)) == NULL)
		{
			ft_dprintf(shell->cur_fd.err, "21sh: cd: %s: %s",
				ft_strequ(*av, "-") ? get_env_var(shell, "OLDPWD") : *av, NOFI);
			return (FAILURE);
		}
		else if (ft_strlen(curpath) + 1 >= PATH_MAX)
			curpath = get_relative_path(&curpath);
	}
	return (change_directory(shell, curpath, *av, option));
}
