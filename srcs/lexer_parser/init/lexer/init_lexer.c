/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 02:50:12 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:00 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void		init_lexing(t_lexinfo *lexinfo)
{
	lexinfo->lexing[L_START] = start_lexer;
	lexinfo->lexing[L_STRING] = string_machine;
	lexinfo->lexing[L_IO_NUMBER] = number_machine;
	lexinfo->lexing[L_SIGN] = sign_machine;
	lexinfo->lexing[L_DSIGN] = double_sign_machine;
	lexinfo->lexing[L_GREATER] = greater_machine;
	lexinfo->lexing[L_LESSER] = lesser_machine;
	lexinfo->lexing[L_GREATAND] = greatand_machine;
	lexinfo->lexing[L_LESSAND] = lessand_machine;
	lexinfo->lexing[L_SQTE] = single_quote_machine;
	lexinfo->lexing[L_DQTE] = double_quote_machine;
	lexinfo->lexing[L_AND] = and_machine;
	lexinfo->lexing[L_OUT] = out_lexer;
	lexinfo->lexing[L_END] = end_machine;
}

void			init_lexinfo(t_registry *shell)
{
	shell->lexinfo.special_signs[0] = E_DAND;
	shell->lexinfo.special_signs[1] = E_OR;
	shell->lexinfo.special_signs[2] = E_DSEMI;
	shell->lexinfo.special_signs[3] = E_DLESS;
	shell->lexinfo.special_signs[4] = E_DGREAT;
	shell->lexinfo.special_signs[5] = E_LESSAND;
	shell->lexinfo.special_signs[6] = E_GREATAND;
	shell->lexinfo.special_signs[7] = E_LESSGREAT;
	shell->lexinfo.special_signs[8] = E_DLESSDASH;
	shell->lexinfo.special_signs[9] = E_CLOBBER;
	shell->lexinfo.special_signs[10] = E_DEQ;
	shell->lexinfo.special_signs[11] = E_NOTEQ;
	shell->lexinfo.special_signs[12] = E_ANDGREAT;
	shell->lexinfo.special_signs[13] = E_ANDDGREAT;
	shell->lexinfo.duplicate[0] = E_STRING;
	shell->lexinfo.duplicate[1] = E_IO_NUMBER;
	shell->lexinfo.duplicate[2] = E_DB_QUOTE;
	shell->lexinfo.duplicate[3] = E_ASSIGN;
	shell->lexinfo.duplicate[4] = E_SPSTRING;
	init_lexing(&shell->lexinfo);
}
