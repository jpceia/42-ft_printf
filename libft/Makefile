NAME		= libft.a

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		:= $(shell find $(SRC_DIR) -name "*.c" -type f)
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			= gcc
RM			= rm -f
OS          = $(shell uname)

FLAGS_WARN  = -Wall -Wextra -Werror
FLAGS_INC   = -I.
FLAGS_OPT   = -O3
FLAGS_DEBUG = -DDEBUG

ifeq ($(OS), Linux)
	FLAGS_DEBUG += -ggdb3
else
	FLAGS_DEBUG += -g
endif

CFLAGS		= $(FLAGS_WARN) $(FLAGS_INC) $(FLAGS_OPT)

all:		$(NAME)

# Compilation
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Generate libft.a
$(NAME):	$(OBJS)
			ar rcs $@ $(OBJS)

# Cleaning
clean:
			$(RM) -rf $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

# Rebuid
re:			fclean $(NAME)

# Debugging build
# We remove FLAGS_OPT and add FLAGS_DEBUG to CFLAGS
debug:      CFLAGS = $(FLAGS_WARN) $(FLAGS_INC) $(FLAGS_DEBUG)
debug:      re


.PHONY:		all clean fclean re debug
