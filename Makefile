# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 00:05:50 by jpceia            #+#    #+#              #
#    Updated: 2021/11/18 00:12:55 by jpceia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

FT_DIR      = ./libft

INC_DIR     = headers

SRC_DIR     = src
OBJ_DIR     = obj

SRCS		= 					\
			ft_printf.c			\
			utils.c				\
			parse_spec.c		\
			print_string.c		\
			print_char.c		\
			print_signed.c		\
			print_unsigned.c 	\
			print_pointer.c

SRCS		:= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC          = gcc
AR		   = ar rcs
RM          = rm -f

OS          = $(shell uname)

FLAGS_WARN  = -Wall -Wextra -Werror
FLAGS_INC   = -I$(INC_DIR) -I$(FT_DIR)
FLAGS_DEBUG = -g -DDEBUG
FLAGS_OPT   = -O3
FLAGS_FT    = -L$(FT_DIR) -lft

CFLAGS      = $(FLAGS_WARN) $(FLAGS_OPT) $(FLAGS_INC) 
LDFLAGS     = $(FLAGS_WARN) $(FLAGS_OPT) $(FLAGS_FT)

all:        $(NAME)

# Compilation
$(OBJ_DIR)/%.o:  $(SRC_DIR)/%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

libft:
			$(MAKE) -C $(FT_DIR)

# Library creation
$(NAME):	$(OBJS)
			$(MAKE) -C $(FT_DIR)
			$(AR) $@ $^
			

# Bonus
bonus:	  $(NAME)

# Cleaning
clean:
			$(MAKE) -C $(FT_DIR) clean
			$(RM) -rf $(OBJ_DIR)

fclean:     clean
			$(MAKE) -C $(FT_DIR) fclean
			$(RM) $(NAME)

# Debugging build
debug:      CFLAGS += $(FLAGS_DEBUG)
debug:      LDFLAGS += $(FLAGS_DEBUG)
debug:      re

# Rebuid
re:         fclean all

# Dynamic linking
so:
			$(CC) -fPIC $(CFLAGS) -c $(SRCS)
			gcc -shared -o libft.so $(OBJS)

.PHONY:     all clean fclean re so bonus debug