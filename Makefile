# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 18:34:36 by ffoissey          #+#    #+#              #
#    Updated: 2019/05/07 21:00:30 by skuppers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#								 Build Targets                                 #
# ---------------------------------------------------------------------------- #

NAME = 21sh
NAMEDB = 21shdb
NAMET = unit
LIBFT = libft.a
LIBFTDB = libftdb.a
SRCS = $(LINE) $(LEXER) $(PARSER) $(BUILTIN) $(TOOLS) $(EXPANSION) $(INIT) $(STARTUP)
OBJM = $(patsubst %.c, $(OPATH)%.o, $(LINEM))
OBJS = $(patsubst %.c, $(OPATH)%.o, $(SRCS))
OBJT = $(patsubst %.c, $(OPATH)%.o, $(UNIT) $(UNITM))
OBJD = $(patsubst %.c, $(OPATH)db%.o, $(LINEM) $(SRCS))
LIB = $(addprefix $(LPATH), $(LIBFT))
LIBDB = $(addprefix $(LPATH), $(LIBFTDB))

# ---------------------------------------------------------------------------- #
#									Compiler                                   #
# ---------------------------------------------------------------------------- #

CC = clang
LINK = $(CC)
LINKD = $(CC) -g3
COMPILE = $(CC) -c
DEBUG = $(CC) -g3 -c
DBRUN =

# ---------------------------------------------------------------------------- #
#									Commands                                   #
# ---------------------------------------------------------------------------- #

MKDIR = mkdir -p
CLEANUP = rm -rf
PRINT = printf
CLEAR = clear
TOUCH = touch

# ---------------------------------------------------------------------------- #
#									 Output                                    #
# ---------------------------------------------------------------------------- #

# One Line
ONELINE =\e[1A\r

# Colors
NC = \033[0m
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

# ---------------------------------------------------------------------------- #
#								  Directories                                  #
# ---------------------------------------------------------------------------- #

LPATH = libft/
OPATH = objs/
IPATH += includes/
IPATH += libft/includes/
TPATH += unit-tests/
TPATH += unit-tests/interface/
TPATH += unit-tests/lexer/
P_STARTUP = startup/
P_LINE += interface/
P_LINE += interface/prompt
P_LINE += interface/action_keys/
P_LINE += interface/history/
P_LINE += interface/action_keys/clipboard/
P_LINE += interface/action_keys/movement/
P_LINE += interface/core/
P_LINE += interface/init/
P_LINE += interface/redraw/
P_LINE += interface/utils/
P_LINE += resolution/
P_LINE += logging/
P_LINE += signals/
P_LINE += ./
P_LEXER += lexer_parser/lexer/
P_PARSER += lexer_parser/parser/grammar_parser
P_PARSER += lexer_parser/parser/application_parser
P_BUILTIN += builtin/
P_BUILTIN += builtin/cd_blt
P_BUILTIN += builtin/echo_blt
P_BUILTIN += builtin/env_blt
P_BUILTIN += builtin/exit_blt
P_BUILTIN += builtin/export_blt
P_BUILTIN += builtin/hash_blt
P_BUILTIN += builtin/intern_blt
P_BUILTIN += builtin/pwd_blt
P_BUILTIN += builtin/set_blt
P_BUILTIN += builtin/setenv_blt
P_BUILTIN += builtin/type_blt
P_BUILTIN += builtin/unset_blt
P_BUILTIN += builtin/unsetenv_blt
P_EXPANSION += expansion/
P_TOOLS += tools/
P_INIT += lexer_parser/init/app_parser/
P_INIT += lexer_parser/init/grammar_parser/
P_INIT += lexer_parser/init/lexer/
_SPATH += $(P_LINE) $(P_LEXER) $(P_PARSER) $(P_BUILTIN) $(P_TOOLS) $(P_EXPANSION)
_SPATH += $(P_INIT) $(P_STARTUP)
SPATH += $(addprefix srcs/, $(_SPATH))

# ---------------------------------------------------------------------------- #
#									 vpath                                     #
# ---------------------------------------------------------------------------- #

vpath %.c $(SPATH) $(TPATH)
vpath %.h $(IPATH)

# ---------------------------------------------------------------------------- #
#							   Compilation Flags                               #
# ---------------------------------------------------------------------------- #

IFLAGS = $(addprefix -I, $(IPATH))
LDLIBN = -lft
LDLIBD = -lftdb
LDFLAGS = -L $(LPATH)
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += $(IFLAGS)
DFLAGS = $(CFLAGS) -fsanitize=address,undefined
LFLAGS = -ltermcap

# ---------------------------------------------------------------------------- #
#									Includes                                   #
# ---------------------------------------------------------------------------- #

INCS += sh21.h
INCS += log.h
INCS += interface_functions.h
INCS += unit.h
INCS += lexer.h
INCS += parser.h
INCS += builtin.h
INCS += resolve.h
INCS += history.h
INCS += define.h
INCS += struct.h
INCS += enum.h

# ---------------------------------------------------------------------------- #
#									Sources                                    #
# ---------------------------------------------------------------------------- #

#							- - - - - Unit - - - - -                           #

UNITM = unit.c
LINEM = main.c

#						- - - - -  Unit-test  - - - - -						   #

UNIT += create_virt_registry.c
UNIT += 00-machine.c
UNIT += clipboard_copy.c
UNIT += clipboard_cut.c
UNIT += clipboard_paste.c

#						- - - - -   Startup   - - - - -						   #

STARTUP += launch.c
STARTUP += options.c
STARTUP += routines.c

#						- - - - -  Debug Log  - - - - -						   #

LINE += debug_logger.c
LINE += print_debug.c

#						- - - - -  Built-in   - - - - -                        #

BUILTIN += blt_tools.c

#CD
BUILTIN += cd_blt.c
BUILTIN += cd_blt_cdpath.c
BUILTIN += cd_blt_additions.c
BUILTIN += cd_blt_simple.c

#ECHO
BUILTIN += echo_blt.c

#ENV
BUILTIN += env_blt.c

#EXIT
BUILTIN += exit_blt.c

#EXPORT
BUILTIN += export_blt.c

#HASH
BUILTIN += hash_blt.c

#INTERN
BUILTIN += intern_blt.c

#PWD
BUILTIN += pwd_blt.c

#SET
BUILTIN += set_blt.c

#SETENV
BUILTIN += setenv_blt.c

#TYPE
BUILTIN += type_blt.c

#UNSET
BUILTIN += unset_blt.c

#UNSETENV
BUILTIN += unsetenv_blt.c

#						- - - - - Line edtion - - - - -                        #

#History
LINE += history.c

#Signals
LINE += signal_handler.c
LINE += itf_signals.c
LINE += exec_signals.c

#Utilities
LINE += validate_interface.c
LINE += get_prompt_len.c
LINE += input_tools.c
LINE += shift_tools.c
LINE += move_tools.c
LINE += realloc_vector.c
LINE += clean_registry.c
LINE += set_quote.c
LINE += ft_putc.c
LINE += is_eof.c
LINE += print.c

#Redraw
LINE += clean_screen.c
LINE += redraw_prompt.c

#Initialization
LINE += load_interface_config.c
LINE += load_termcap_strings.c

#Core
LINE += window_cursor.c
LINE += term_mode.c
LINE += launch_interface.c
LINE += validate_quoting.c
LINE += handle_input_keys.c

#Prompt
LINE += prompt.c
LINE += sub_prompt.c

#Action keys
LINE += init_clipboard.c
LINE += init_ak_keycodes.c
LINE += execute_clipboard_copy_ak.c
LINE += execute_clipboard_cut_ak.c
LINE += execute_clipboard_paste.c
LINE += execute_arrow_ak.c
LINE += execute_he_ak.c
LINE += execute_word_jumping_ak.c
LINE += execute_ctrl_ak.c
LINE += execute_special_ak.c

#			 		   - - - - - Lexer - Parser - - - - -                      #

#Init
INIT += init_parser.c
INIT += init_io_parser.c
INIT += init_io_redirect_parser.c
INIT += init_string_parser.c
INIT += init_start_parser.c
INIT += init_heredoc_parser.c
INIT += generate_graph.c
INIT += ways_graph.c
INIT += ways_graph_word.c
INIT += init_lexer.c

#Lexer
LEXER += lexer.c
LEXER += machine_interface.c
LEXER += states.c
LEXER += generate_token.c
LEXER += quotes_states.c
LEXER += sign_states.c
LEXER += tmp_display.c
LEXER += redirect_states.c

#Grammar Parser
PARSER += grammar_parser.c
PARSER += parser_debug.c

#Application Parser
PARSER += parser_state.c
PARSER += parser_interface.c
PARSER += string_parser.c
PARSER += redirect_parser.c
PARSER += pipe_parser.c
PARSER += io_redirect_parser.c
PARSER += filename_parser.c
PARSER += heredoc_parser.c
PARSER += parser_tools.c

#						   - - - - Expansion - - - -                           #
EXPANSION += expansion.c
EXPANSION += tilde.c
EXPANSION += variable.c
EXPANSION += quoting.c

#						   - - - -    Tool    - - - -                          #

TOOLS += list_functions.c
TOOLS += list_functions2.c
TOOLS += free.c
TOOLS += free_node.c
TOOLS += utils.c
TOOLS += print_opt.c
TOOLS += read_filedesc.c
TOOLS += internals.c

#						   - - - - Resolution - - - -                          #

LINE += job_tools.c
LINE += launch_job.c
LINE += launch_process.c
LINE += waitjob.c



# ---------------------------------------------------------------------------- #
#									 Rules                                     #
# ---------------------------------------------------------------------------- #

all : $(NAME)

run : $(NAME)
	./$<

drun : $(NAMEDB)
		./$< -d

debug : $(NAMEDB)

lldb : $(NAMEDB)
	lldb -- ./$< -d

test : $(NAMET)
	./$<

#					 - - - - - Normal Compilation - - - - -                    #

$(NAME) : $(CLEAR) $(LIB) $(OPATH) $(OBJS) $(OBJM)
	$(LINK) $(OBJS) $(OBJM) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBN) $(LFLAGS) -o $@
	$(PRINT) "$(GREEN)$@ is ready\n$(NC)"

$(OBJM) : $(OPATH)%.o : %.c $(INCS) Makefile
	$(COMPILE) $(CFLAGS) $(CPPFLAGS) $< -o $@
	$(PRINT) "$(ONELINE)$(BLUE)Compiling $<                   $(NC)\n"

$(OBJS) : $(OPATH)%.o : %.c $(INCS) Makefile
	$(COMPILE) $(CFLAGS) $(CPPFLAGS) $< -o $@
	$(PRINT) "$(ONELINE)$(BLUE)Compiling $<                   $(NC)\n"

$(LIB) : FORCE
	$(MAKE) -C $(LPATH)

#					 - - - - Unit test Compilation - - - -                     #

$(NAMET) : $(CLEAR) $(LIB) $(OPATH) $(OBJS) $(OBJT)
	$(LINK) $(CFLAGS)  $(LDFLAGS) $(LDLIBN) $(LFLAGS) -fsanitize=address,undefined,leak -o  $@ $(OBJT) $(OBJS)
	$(PRINT) "$(GREEN)$@ is ready\n$(NC)"

$(OBJT) : $(OPATH)%.o : %.c $(INCS) Makefile
	$(COMPILE) $(CFLAGS)  $< -o $@
	$(PRINT) "$(ONELINE)$(BLUE)Compiling $<                   $(NC)\n"

#					 - - - - - Debug Compilation - - - - -                     #

$(NAMEDB) : $(CLEAR) $(LIBDB) $(OPATH) $(OBJD)
	$(LINKD) $(OBJD) $(DFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBD) $(LFLAGS) -o $@
	$(PRINT) "$(GREEN)$@ is ready\n$(NC)"

$(OBJD) : $(OPATH)db%.o : %.c $(INCS) Makefile
	$(DEBUG) $(DFLAGS) $(CPPFLAGS) $< -o $@
	$(PRINT) "$(ONELINE)$(BLUE)Compiling $< for debug                   $(NC)\n"

$(LIBDB) : FORCE
	$(MAKE) -C $(LPATH) debug

$(CLEAR):
	$@

$(OPATH) :
	$(MKDIR) $(OPATH)

clean :
	$(MAKE) -C $(LPATH) clean
	$(CLEANUP) $(OPATH)
	$(CLEANUP) $(NAME).dSYM
	$(PRINT) ".o file deleted\n"

fclean : clean
	$(MAKE) -C $(LPATH) fclean
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(NAMEDB)
	$(CLEANUP) $(NAMET)
	$(PRINT) "Executables destroyed\n"

re : fclean all

help :
	@$(PRINT) "Rules available : all, clean,  fclean, re, and help\n"

FORCE:

.PHONY : all 21 21debug lexer lexerdb clean fclean re help FORCE
.SILENT:
