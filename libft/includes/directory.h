/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 06:52:58 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:23 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTORY_H
# define DIRECTORY_H
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include "list.h"

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

typedef struct			s_status
{
	t_stat				info;
	char				*path;
	char				*name;
}						t_status;

int						ft_dirlist(t_list **dirlist, char *path);
void					ft_dirdel(t_list **dirlist);
int						ft_checkstat(char *file, mode_t st_mode);
#endif
