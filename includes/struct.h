/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:25:34 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:22 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "define.h"
# include "enum.h"
# include "libft.h"

/*
*****************************************************
********************** BUILTIN **********************
*****************************************************
*/

typedef uint16_t		t_option;
typedef t_option		(*t_get_option)(char *s, t_option option);

/*
*****************************************************
*********************** LEXER ***********************
*****************************************************
*/

typedef struct s_lexer	t_lexer;
typedef void			(*t_lexing)(t_lexer *);
typedef enum e_type		t_type;

typedef struct			s_token
{
	char				*data;
	enum e_type			type;
}						t_token;

typedef struct			s_lexinfo
{
	t_lexing			lexing[STATENBR];
	enum e_type			duplicate[TOKEN_WITH_DATA];
	enum e_type			special_signs[SPECIAL_SIGNS];
}						t_lexinfo;

struct					s_lexer
{
	char				*input;
	char				buffer[BUFFER];
	char				*data;
	unsigned int		buffer_index;
	t_lexinfo			*lexinfo;
	t_list				*tokens;
	enum e_lexer_state	state;
	enum e_quote		quote;
	enum e_type			last_lexer;
	int					io_detect;
};

/*
*****************************************************
********************** PARSER ***********************
*****************************************************
*/

typedef struct s_graph	t_graph;
typedef struct s_parser	t_parser;
typedef void			(*t_parsing)(t_parser *);
typedef t_parsing		t_pstate[PARSE_STATES][NB_OF_TOKENS];

typedef struct			s_filedesc
{
	unsigned int		action;
	int32_t				first;
	int32_t				second;
}						t_filedesc;

typedef struct			s_process
{
	t_list				*fd;
	char				**av;
	char				**env;
	uint8_t				completed;
	uint8_t				stopped;
	pid_t				pid;
	int					status;
}						t_process;

typedef struct			s_job
{
	char				*command;
	t_list				*process_list;
	struct termios		*term_modes;
	pid_t				pgid;
	t_filedesc			fd;
}						t_job;

struct					s_parser
{
	t_list				*token_list;
	t_list				*env;
	t_list				*tmp_env;
	t_list				*job_list;
	t_process			process;
	t_job				job;
	t_stack				stack;
	t_token				token;
	unsigned int		special_case;
	enum e_parser_state	last_state;
	enum e_parser_state	state;
	int					oflags;
	int					valid;
};

struct					s_graph
{
	enum e_type			*good_type;
};

/*
*****************************************************
********************** HISTORY **********************
*****************************************************
*/

typedef struct			s_history
{
	char				*command;
	struct s_history	*next;
	struct s_history	*prev;
}						t_history;

/*
*****************************************************
**************** INTERFACE_FUNCTIONS ****************
*****************************************************
*/

typedef struct s_registry	t_registry;

typedef struct			s_termcaps
{
	char				*clear;
	char				*cs_down;
	char				*cs_right;
	char				*cs_left;
	char				*cs_up;
}						t_termcaps;

typedef struct			s_cursor
{
	uint32_t			index;
	uint32_t			x;
	uint32_t			y;
}						t_cursor;

typedef struct			s_window
{
	uint32_t			rows;
	uint32_t			cols;
	uint32_t			max_chars;
}						t_window;

typedef struct			s_interface
{
	struct termios		*term_mode;
	struct termios		*orig_mode;
	t_vector			*line;
	t_vector			*clip;
	t_history			*history_head;
	t_history			*hist_ptr;
	char				*current_line;
	char				*state;
	t_cursor			cursor;
	t_window			window;
	t_termcaps			termcaps;
	uint64_t			ak_masks[AK_AMOUNT];
	int8_t				(*tc_call[AK_AMOUNT])(struct s_registry *shell);
	uint8_t				allow_input;
}						t_interface;

/*
*****************************************************
********************** COMMON ***********************
*****************************************************
*/

typedef struct			s_opt
{
	char				*command_str;
	t_option			option;
}						t_opt;

typedef struct			s_variable
{
	char				*name;
	char				*data;
}						t_variable;

typedef struct			s_fd
{
	int					in;
	int					out;
	int					err;
}						t_fd;

struct					s_registry
{
	const char			**grammar;
	t_graph				graph[NB_OF_TOKENS];
	t_lexinfo			lexinfo;
	t_pstate			parsing;
	t_list				*env;
	t_list				*intern;
	t_list				*current_job;
	t_hash				bin_hashmap;
	t_hash				blt_hashmap;
	struct s_interface	interface;
	uint8_t				is_interactive;
	uint8_t				parse_signal;
	t_opt				option;
	t_fd				cur_fd;
};

typedef int				(*t_builtin) (t_registry *, char **);

extern t_registry		*g_shell;

/*
*****************************************************
********************** RESOLVE **********************
*****************************************************
*/

extern t_list			*g_job_head;

#endif
