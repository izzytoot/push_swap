# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 13:30:18 by icunha-t          #+#    #+#              #
#    Updated: 2024/12/05 15:26:01 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                NAMES & PATHS                                 #
#==============================================================================#
NAME = libft.a 

HEADER_PATH = ./libft/libft.h
BASIC_PATH = ./libft/basic
PRINTF_PATH = ./libft/printf
GNL_PATH = ./libft/gnl
EXTRAS_PATH = ./libft/extras

SRCS = $(addprefix $(BASIC_PATH)/, ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_memchr.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_itoa.c)
PRINTF_SRCS = $(addprefix $(PRINTF_PATH)/, src/ft_printf.c src/ft_printchar.c src/ft_printstr.c src/ft_printint_nb.c src/ft_printint_u.c src/ft_printint_hex.c src/ft_printptr.c)
GNL_SRCS = $(addprefix $(GNL_PATH)/, get_next_line_bonus.c get_next_line_utils_bonus.c)
EXTRAS_SRCS = $(addprefix $(EXTRAS_PATH)/, ft_free.c)

OBJS = $(SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)
EXTRAS_OBJS = $(EXTRAS_SRCS:.c=.o)
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
all: extra $(NAME)

%.o: %.c $(HEADER_PATH)
	$(C_COMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo $(GREEN) "$(NAME) was created successfully!" $(RESET)

extra: $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS) $(EXTRAS_OBJS)
	@$(AR) $(NAME) $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS) $(EXTRAS_OBJS)
	@echo $(GREEN) "$(NAME) was created with extras successfully!" $(RESET)

#==============================================================================#
#                                  CLEAN RULES                                 #
#==============================================================================#
clean:
	@$(RM) -f $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS) $(EXTRAS_OBJS)
	@echo $(RED) "All .o files were deleted!" $(RESET)
	
fclean: clean
	@$(RM) $(NAME)
	@echo $(RED) "$(NAME) was deleted!" $(RESET)

re: fclean all

.PHONY: all clean fclean re extra
