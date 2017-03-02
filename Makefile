#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivanov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:55:45 by mivanov           #+#    #+#              #
#    Updated: 2017/02/24 15:41:49 by mivanov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

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
