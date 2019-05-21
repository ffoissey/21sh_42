/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:27:44 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:22 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_H
# define UNIT_H

# include "sh21.h"
# include "log.h"
# include "interface_functions.h"
# include <stdlib.h>

t_result	test_virt_registry(int print_on);
t_result	test_clipboard_copy(int print_on);
t_result	test_clipboard_cut(int print_on);
t_result	test_clipboard_paste(int print_on);
t_result	basic_lexer_test(int print_on);
int			create_virtual_registry(t_registry **sh, t_interface **itf);

#endif
