/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ak_keycodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:48:38 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:56 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_functions.h"

void	setup_keycodes(t_interface *itf)
{
	ft_memset(itf->ak_masks, 0, (sizeof(unsigned long) * AK_AMOUNT));
	itf->ak_masks[AK_ARROW_RIGHT] = AK_ARROW_RIGHT_MASK;
	itf->ak_masks[AK_ARROW_LEFT] = AK_ARROW_LEFT_MASK;
	itf->ak_masks[AK_ARROW_UP] = AK_ARROW_UP_MASK;
	itf->ak_masks[AK_ARROW_DOWN] = AK_ARROW_DOWN_MASK;
	itf->ak_masks[AK_HOME] = AK_HOME_MASK;
	itf->ak_masks[AK_END] = AK_END_MASK;
	itf->ak_masks[AK_BACKSPACE] = AK_BACKSPACE_MASK;
	itf->ak_masks[AK_DELETE] = AK_DELETE_MASK;
	itf->ak_masks[AK_CTRL_A] = AK_CTRL_A_MASK;
	itf->ak_masks[AK_CTRL_D] = AK_CTRL_D_MASK;
	itf->ak_masks[AK_CTRL_E] = AK_CTRL_E_MASK;
	itf->ak_masks[AK_CTRL_L] = AK_CTRL_L_MASK;
	itf->ak_masks[AK_CTRL_X] = AK_CTRL_X_MASK;
	itf->ak_masks[AK_CTRL_B] = AK_CTRL_B_MASK;
	itf->ak_masks[AK_CTRL_P] = AK_CTRL_P_MASK;
	itf->ak_masks[AK_CTRL_LB] = AK_CTRL_LB_MASK;
	itf->ak_masks[AK_CTRL_RB] = AK_CTRL_RB_MASK;
	itf->ak_masks[AK_CTRL_F] = AK_CTRL_F_MASK;
	itf->ak_masks[AK_CTRL_R] = AK_CTRL_R_MASK;
	itf->ak_masks[AK_CTRL_LEFT] = AK_CTRL_LEFT_MASK;
	itf->ak_masks[AK_CTRL_RIGHT] = AK_CTRL_RIGHT_MASK;
	itf->ak_masks[AK_TABULATION] = AK_TAB_MASK;
	itf->ak_masks[AK_CTRL_DOWN] = AK_CTRL_DOWN_MASK;
	itf->ak_masks[AK_CTRL_UP] = AK_CTRL_UP_MASK;
}
