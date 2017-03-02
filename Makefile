NAME =  libftprintf.a

CFLAGS = -O0

INCLUDES = -I.

OBJECTS = $(SRC:.c=.o)

SRC = ft_isdigit.c \
		ft_printf.c	\
		ft_struct_fill.c \
		ft_print_struct.c \
		ft_putnbr.c \
		ft_print_text.c \
		ft_struct.c	\
		pf_cast.c \
		ft_strlen.c \
		ft_strchr.c \


all : $(NAME)

$(NAME) :
		gcc -c $(CFLAGS) $(SRC) $(INCLUDES)
		ar -cru $(NAME) $(OBJECTS)
clean :
		rm -rf $(OBJECTS)

fclean : clean
		rm -rf $(NAME)

re : fclean all
