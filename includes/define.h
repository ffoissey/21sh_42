/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:17:21 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:22 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
*****************************************************
******** -------------- SIGNAL -------------- *******
*****************************************************
*/

# define SSIG_KILL                  9
# define SSIG_INT                   2
# define SSIG_QUIT                  3
# define SSIG_STOP                  19
# define SSIG_SEGV					11
# define SSIG_ABT					6

/*
*****************************************************
******** -------------- COMMON -------------- *******
*****************************************************
*/

# define SUCCESS					0
# define FAILURE					-1
# define FALSE						0
# define TRUE						1
# define SH21_USAGE_1				"Usage: 21sh [long option] [-dh] "
# define SH21_USAGE_2				"[-c CMD]\n"
# define SH21_USAGE_LONG_OPTION		"\n\t--help\n\t"
# define SH21_USAGE_LONG_OPTION_2	"--debug\n"
# define NO_OPT						0x000
# define HELP_OPT					0x001
# define COMMAND_OPT				0x002
# define DEBUG_OPT					0x004
# define HMAP_BIN_SIZE				4096
# define HMAP_BLT_SIZE				32
# define SET_TERM					0
# define RESTORE_TERM				1

/*
*****************************************************
********************** BUILTIN **********************
*****************************************************
*/

# define A_OPT						0x001
# define F_OPT						0x002
# define I_OPT						0x004
# define L_OPT						0x008
# define N_OPT						0x010
# define P_OPT						0x020
# define T_OPT						0x040
# define P_LOW_OPT					0x080
# define ERROR_OPT					0x800
# define CD_USAGE 					"cd: usage: cd [-L|-P] [dir]\n"
# define CD_ERROR_OLDPWD_NOTSET		"21sh: cd: OLDPWD not set\n"
# define NOFI 						"No such file or directory\n"
# define ENV_USAGE_1 				"env: usage: env [-i] [name=value]... "
# define ENV_USAGE_2 				"[utility [argument]...]\n"
# define SETENV_USAGE 				"setenv: usage: setenv [name [value]]\n"
# define UNSETENV_USAGE 			"unsetenv: usage: unsetenv name\n"
# define EXPORT_USAGE 				"type: usage: export name[=value] ...\n"
# define UNSET_USAGE 				"type: usage: unset name\n"

/*
*****************************************************
********************* INTERNALS *********************
*****************************************************
*/

# define IFS_CHAR					10
# define READ_SIZE					8
# define CLIPBOARD_SZ				32
# define INT_TERM					"TERM"
# define INT_TERM_DFLT_VALUE		"xterm-256color"
# define INT_DBG_FD					"DEBUG_FD"
# define INT_DBG_FILE				".42sh.log"
# define INT_ROWS					"ROWS"
# define INT_COLS					"COLS"
# define INT_PS1					"PS1"
# define INT_PS2					"PS2"
# define INT_PS3					"PS3"
# define INT_PS4					"PS4"
# define INT_PS5					"PS5"
# define INT_ESCAPE_SEQ				"ESC"
# define INT_PS1_VALUE				"[ 21sh ]-> "
# define INT_PS2_VALUE				"quote> "
# define INT_PS3_VALUE				"script> "
# define INT_PS4_VALUE				"heredoc> "
# define INT_ESCAPE_SEQ_VALUE		"\\"
# define INT_MAGIC_NUMBER			"4242"

/*
*****************************************************
*********************** LEXER ***********************
*****************************************************
*/

# define STATENBR					17
# define TOKEN_WITH_DATA			5
# define NB_OF_TOKENS				50
# define BUFFER						131071
# define SINGLE_SIGNS				16
# define SPECIAL_SIGNS				14
# define SIGNS 						30
# define ALLCHAR					"\"|()><;`&{}[]#%\n"
# define SIGN_DETECT				" \t<>|;&!=\n"
# define LETTER_TO_QUOTE			"\"\'$"
# define LETTER_INTERUPT			" \t<>|;&\n"
# define LETTER_SPECIAL				"\"\'\\$~*?"
# define TILDE_INTERUPT				" /$"
# define QSP_INT					" \"\'"
/*
** 42sh
** # define LETTER_INTERUPT			" \t<>|;\'\"`()$&!?{}[]*%\\"
** # define SIGN_DETECT				" \t<>|;\'\"`()$&!?{}[]*%\\="
*/
# define QUOTE_INTERUPT				"\\\"`$"
# define EXP_INTERUPT				" \t\'\"`$/"
# define DOUBLE_SIGN				"&|;=!"

/*
*****************************************************
********************** PARSER ***********************
*****************************************************
*/

# define PARSE_STATES				30
# define FD_DUP						0x01
# define FD_CLOSE					0x02
# define FD_WRITE					0x04
# define FD_READ					0x08
# define FD_PIPE					0x10
# define FD_CLOED					0x20

# define QUOTING					0x01
# define HERETRIM					0x02
# define TO_CLOSE					0x04
# define NO_PIPE					0x08
# define VALID_PROCESS				0x10

# define REDIR						E_GREAT, E_LESS
# define REDIR_AND					E_GREATAND, E_LESSAND, E_ANDGREAT
# define REDIR_DB					E_DGREAT, E_DLESS, E_DLESSDASH, E_ANDDGREAT
# define ALL_REDIRECT				REDIR, REDIR_DB, REDIR_AND
# define WORD						E_STRING, E_SPSTRING, E_DB_QUOTE
# define END_CMD					E_NEWLINE, E_END, E_SEMICOLON
# define E_START					E_DEFAULT

# define N_DB_QUOTE					"\""
# define N_PIPE						"|"
# define N_PARENT_OPEN				"("
# define N_PARENT_CLOSE				")"
# define N_GREAT					">"
# define N_LESS						"<"
# define N_SEMICOLON				";"
# define N_BACKQUOTE				"`"
# define N_AND						"&"
# define N_HOOK_OPEN				"{"
# define N_HOOK_CLOSE				"}"
# define N_BRACKET_OPEN				"["
# define N_BRACKET_CLOSE			"]"
# define N_HASH						"#"
# define N_PERCENT					"%"
# define N_NEWLINE					"\\n"
# define N_DAND						"&&"
# define N_OR						"||"
# define N_DSEMI					";;"
# define N_DLESS					"<<"
# define N_DGREAT					">>"
# define N_LESSAND					"<&"
# define N_GREATAND					">&"
# define N_LESSGREAT				"<>"
# define N_ANDDGREAT				"&>>"
# define N_ANDGREAT					"&>"
# define N_DLESSDASH				"<<-"
# define N_CLOBBER					">|"
# define N_DEQ						"=="
# define N_NOTEQ					"!="
# define N_CASE						"case"
# define N_DO						"do"
# define N_DONE						"done"
# define N_ELIF						"elif"
# define N_ELSE						"else"
# define N_ESAC						"esac"
# define N_FI						"fi"
# define N_FOR						"for"
# define N_IF						"if"
# define N_IN						"in"
# define N_THEN						"then"
# define N_UNTIL					"until"
# define N_WHILE					"while"
# define N_IO_NUMBER				"IO number"
# define N_ASSIGN					"assign (=)"
# define N_STRING					"word"
# define N_SPSTRING					"spword"
# define N_END						"end"
# define N_ERROR					"ERROR"
# define N_START					"START"

/*
*****************************************************
**************** INTERFACE_FUNCTIONS ****************
*****************************************************
*/

# define FAIL_EOF					42
# define AK_AMOUNT					24
# define AK_ARROW_UP_MASK			0x1b5b410000000000
# define AK_ARROW_DOWN_MASK 		0x1b5b420000000000
# define AK_ARROW_RIGHT_MASK		0x1b5b430000000000
# define AK_ARROW_LEFT_MASK 		0x1b5b440000000000
# define AK_HOME_MASK 				0x1b5b480000000000
# define AK_END_MASK 				0x1b5b460000000000
# define AK_CTRL_A_MASK 			0x0100000000000000
# define AK_CTRL_E_MASK		   		0x0500000000000000
# define AK_DELETE_MASK		   		0x1b5b337e00000000
# define AK_BACKSPACE_MASK		 	0x7f00000000000000
# define AK_CTRL_D_MASK 			0x0400000000000000
# define AK_CTRL_L_MASK				0x0c00000000000000
# define AK_CTRL_X_MASK				0x1800000000000000
# define AK_CTRL_B_MASK				0x0200000000000000
# define AK_CTRL_P_MASK				0x1000000000000000
# define AK_CTRL_LB_MASK			0x1b00000000000000
# define AK_CTRL_RB_MASK			0x1d00000000000000
# define AK_CTRL_F_MASK				0x0600000000000000
# define AK_CTRL_R_MASK				0x1200000000000000
# define AK_CTRL_UP_MASK			0x1b5b313b35410000
# define AK_CTRL_DOWN_MASK			0x1b5b313b35420000
# define AK_CTRL_RIGHT_MASK			0x1b5b313b35430000
# define AK_CTRL_LEFT_MASK			0x1b5b313b35440000
# define AK_TAB_MASK				0x0900000000000000

/*
*****************************************************
************************ LOG ************************
*****************************************************
*/

# define LOG_OK						"[OK]"
# define LOG_INFO 					"[INFO]"
# define LOG_WARNING				"[WARNING]"
# define LOG_ERROR					"[ERROR]"
# define LOG_CRITICAL				"[CRITICAL]"

/*
*****************************************************
********************** HISTORY **********************
*****************************************************
*/

# define DEFAULT_HISTORY_FILENAME	".sh_history"

/*
*****************************************************
*********************** UNIT ************************
*****************************************************
*/

# define BLUE						"39"
# define T_CHMOD					766

#endif
