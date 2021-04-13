INCDIR		= .

LIBFTDIR	= ./libft
LIBFT		= libft/libft.a

SRCS		= 					\
			ft_printf.c			\
			utils.c				\
			parse_spec.c		\
			print_string.c		\
			print_char.c		\
			print_signed.c		\
			print_unsigned.c 	\
			print_pointer.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

MAKE		= make
CC			= gcc
AR			= ar rc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g

all:		$(NAME)

.c.o:
			${CC} ${CFLAGS} -I${INCDIR} -I$(LIBFTDIR) -c $< -o ${<:.c=.o}

$(LIBFT):
			$(MAKE) bonus -C $(LIBFTDIR)

$(NAME):	$(OBJS) $(LIBFT)
			cp libft/libft.a ./$(NAME)
			$(AR) $(NAME) $(OBJS) $(LIBFT)

clean:
			$(MAKE) -C $(LIBFTDIR) clean
			$(RM) $(OBJS)

fclean:
			$(MAKE) -C $(LIBFTDIR) fclean
			$(RM) $(OBJS)
			$(RM) $(NAME)

re:			fclean all

bonus:		all

so:
			$(CC) -fPIC $(CFLAGS) -c $(SRCS)
			gcc -shared -o libft.so $(OBJS)

.PHONY:		all clean fclean re so bonus
