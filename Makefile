INCDIR		= .

LIBFTDIR	= ./libft
LIBFT		= libft/libft.a

SRCS		= \
			ft_printf.c			\
			ft_printf_type.c	\
			ft_printf_parse.c	\
			ft_printf_str.c		\
			ft_printf_numeric.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

MAKE		= make
CC			= gcc
AR			= ar rc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

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

so:
			$(CC) -fPIC $(CFLAGS) -c $(SRCS)
			gcc -shared -o libft.so $(OBJS)

.PHONY:		all clean fclean re so
