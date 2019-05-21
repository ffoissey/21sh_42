/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:54:02 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:22 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_FUNCTIONS_H
# define INTERFACE_FUNCTIONS_H

# include "struct.h"

/*
*****************************************************
************** INIT / SETTING / FREE ****************
*****************************************************
*/

int8_t		init_window(t_registry *shell);
int8_t		init_cursor(t_registry *shell);
int8_t		init_termcap_calls(t_termcaps *termcp);
void		define_interface_signal_behavior(t_registry *shell);
void		setup_keycodes(t_interface *itf);
short		set_term_behavior(t_registry *shell);
char		set_quote(const char c);
int8_t		load_interface(t_registry *shell);
void		unload_interface(t_interface *itf);
short		restore_term_behavior(t_registry *shell);
void		cleanup_interface(t_registry *shell);
int8_t		update_window(t_registry *shell);

/*
*****************************************************
********** UNIT TESTING / BUFFER / UTILS ************
*****************************************************
*/

void		move_buffer(char *dest, t_vector *source);
void		validate_input_quoting(t_registry *shell, t_interface *itf);
int8_t		fill_interface_related_internals(t_registry *shell);
t_vector	*allocate_clipboard(t_registry *shell);
void		handle_input_key(t_registry *shell, char c[]);
uint32_t	get_next_char(const char *str, uint32_t index
					, const char direction);
void		shift_content_right_once(t_vector *vect, unsigned int cursor);
void		shift_content_left_once(t_vector *vect, unsigned int cursor);
int			ft_putc(const int c);
int8_t		validate_interface_content(t_interface *itf);
uint8_t		is_printable(char c[READ_SIZE]);
uint8_t		is_eof(const char *buffer);
uint32_t	get_prompt_len(t_registry *itf);
uint64_t	compute_mask(char c[READ_SIZE]);
void		reset_vector(t_vector *vect);
void		realloc_vector(t_vector *dest, t_vector *source);
void		link_actions_to_keys(int8_t (*tc_call[AK_AMOUNT])
				(struct s_registry *shell));
int8_t		quoting_is_valid(char *string);

/*
*****************************************************
********************* DISPLAY ***********************
*****************************************************
*/

void		interface_resize_handler(const int signo);
void		print_char(t_interface *itf, const char d);
void		print_words(t_interface *itf, const char *str);
void		redraw_prompt(const int signo);
uint32_t	clean_screen(t_registry *shell);
uint32_t	replace_input_line(t_registry *shell, const char *string);
uint32_t	redraw_input_line(t_registry *shell);
uint32_t	redraw_after_cursor(t_registry *shell);

/*
*****************************************************
********************* PROMPT ************************
*****************************************************
*/

char		*prompt(t_registry *shell);
void		prompt_read_failed(t_registry *shell, t_vector *vect);
int8_t		invoke_sub_prompt(t_registry *shell, char **line,
				char *prompt_state);

/*
*****************************************************
******************** ACTION KEYS ********************
*****************************************************
*/

int8_t		tc_ak_ctrl_d(t_registry *shell);
int8_t		tc_ak_next_word(t_registry *shell);
int8_t		tc_ak_prev_word(t_registry *shell);
int8_t		tc_ak_cut_before_cursor(t_registry *shell);
int8_t		tc_ak_cut_after_cursor(t_registry *shell);
int8_t		tc_ak_copy_before_cursor(t_registry *shell);
int8_t		tc_ak_copy_after_cursor(t_registry *shell);
int8_t		tc_ak_cut_line(t_registry *shell);
int8_t		tc_ak_copy_line(t_registry *shell);
int8_t		tc_ak_paste_clipboard(t_registry *shell);
int8_t		tc_ak_clear_screen(t_registry *shell);
int8_t		tc_ak_home(t_registry *shell);
int8_t		tc_ak_end(t_registry *shell);
int8_t		tc_ak_delete(t_registry *shell);
int8_t		tc_ak_backspace(t_registry *shell);
int8_t		tc_ak_arrow_up(t_registry *shell);
int8_t		tc_ak_arrow_down(t_registry *shell);
int8_t		tc_ak_arrow_left(t_registry *shell);
int8_t		tc_ak_arrow_right(t_registry *shell);
int8_t		tc_ak_hightab(t_registry *shell);
int8_t		tc_ak_ctrl_down(t_registry *shell);
int8_t		tc_ak_ctrl_up(t_registry *shell);

#endif
