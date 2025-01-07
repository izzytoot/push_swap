# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 13:30:18 by icunha-t          #+#    #+#              #
#    Updated: 2025/01/07 16:50:56 by icunha-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                NAMES & PATHS                                 #
#==============================================================================#
NAME = push_swap.a 

EXEC = push_swap

HEADER_PATH = push_swap.h

INIT_PATH = ./ft_init

COMMANDS_PATH = ./ft_commands

SORTING_PATH = ./ft_sorting

SRCS_INIT = $(addprefix $(INIT_PATH)/, error_handling.c split.c stack_init.c utils_stack.c)

SRCS_COMMANDS = $(addprefix $(COMMANDS_PATH)/, c_push.c c_reverse_rotate.c c_rotate.c c_swap.c)

SRCS_SORTING = $(addprefix $(SORTING_PATH)/, costs.c mini_sort.c pivot_and_partitioning.c sorting_alg.c utils_sort.c)

EXEC_SRC = main.c

LIBFT_DIR = ./libft/

LIBFT = ./libft/libft.a

OBJS = $(SRCS_INIT:.c=.o) $(SRCS_COMMANDS:.c=.o) $(SRCS_SORTING:.c=.o)
#==============================================================================#
#                            FLAGS & COMMANDS                                  #
#==============================================================================#
C_COMP = cc

FLAGS = -Wall -Werror -Wextra

FLAGS += -g

RM = rm -f

AR = ar rcs

MAKE = make
#==============================================================================#
#                                  COLORS                                      #
#==============================================================================#
RED		= "\033[0;31m"
GREEN		= "\033[0;32m"  
YELLOW		= "\033[0;33m" 
RESET		= "\033[0m"
#==============================================================================#
#                                  RULES                                       #
#==============================================================================#
all: $(NAME) exec

%.o: %.c 
	@$(C_COMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo $(GREEN) "$(NAME) was created successfully!" $(RESET)

#==============================================================================#
#                                  EXEC                                       #
#==============================================================================#
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

exec: $(LIBFT)
	@$(C_COMP) $(FLAGS) $(SRCS_INIT) $(SRCS_COMMANDS) $(SRCS_SORTING) $(EXEC_SRC) $(LIBFT) $(NAME) -o $(EXEC)
	@echo $(GREEN) "$(EXEC) program was created successfully!"$(RESET)
#==============================================================================#
#                                  CLEAN RULES                                 #
#==============================================================================#
clean:
	@$(RM) -f $(OBJS)
	@echo $(RED) "All .o files were deleted!" $(RESET)

fcleanlib:
	@$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	@$(RM) $(NAME) $(EXEC)
	@echo $(RED) "$(NAME) and $(EXEC) were deleted!" $(RESET)

fcleanall: fcleanlib fclean

re: fclean all

.PHONY: all clean fclean re exec 
