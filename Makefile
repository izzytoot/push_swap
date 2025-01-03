# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 13:30:18 by icunha-t          #+#    #+#              #
#    Updated: 2025/01/03 14:09:05 by icunha-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                NAMES & PATHS                                 #
#==============================================================================#
NAME = push_swap.a 

EXEC = push_swap

HEADER_PATH = push_swap.h

SRCS = c_push.c c_reverse_rotate.c c_rotate.c c_swap.c error_handling.c mini_sort.c split.c stack_init.c list_utils.c pivot_and_partitioning.c

EXEC_SRC = main.c

LIBFT = libft.a

OBJS = $(SRCS:.c=.o)
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
exec:
	@$(C_COMP) $(FLAGS) $(SRCS) $(EXEC_SRC) $(LIBFT) $(NAME) -o $(EXEC)
	@echo $(GREEN) "$(EXEC) program was created successfully!"$(RESET)
#==============================================================================#
#                                  CLEAN RULES                                 #
#==============================================================================#
clean:
	@$(RM) -f $(OBJS)
	@echo $(RED) "All .o files were deleted!" $(RESET)
	
fclean: clean
	@$(RM) $(NAME) $(EXEC)
	@echo $(RED) "$(NAME) and $(EXEC) were deleted!" $(RESET)

re: fclean all

.PHONY: all clean fclean re exec
