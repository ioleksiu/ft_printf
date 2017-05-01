#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:55:45 by ioleksiu          #+#    #+#              #
#    Updated: 2017/02/24 15:41:49 by ioleksiu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =  libftprintf.a

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

SRC = cast_d.c \
		f_oo.c \
		f_p.c \
		ft_isdigit.c \
		ft_put_unbr.c \
		ft_width.c \
		cast_d_u.c	\
		f_ss.c \
		f_proc.c \
		ft_itoa_base.c \
		ft_putnbr.c \
		ft_zero_struct.c \
		cast_du.c \
		f_uu.c \
		f_s.c \
		ft_itoa_base1.c \
		ft_putstr.c \
		parse.c \
		cast_du_x.c \
		f_xx.c \
		f_u.c \
		ft_itoa_base4.c \
		ft_size.c \
		count_num.c	\
		f_c.c \
		f_x.c \
		ft_print_text.c \
		ft_strchr.c \
		put_nchar.c \
		count_unum.c \
		f_d.c \
		ft_dot.c \
		ft_printf.c	\
		ft_strlen.c \
		f_dd.c \
		f_o.c \
		ft_flags.c \
		ft_put_strn.c \
		ft_struct.c \
		b_n.c \
		struct_fill.c \
		pf_cast.c \
		ft_strdup.c \

all : $(NAME)

$(NAME) :
		gcc -c $(CFLAGS) $(SRC)
		ar -cru $(NAME) $(OBJECTS)
clean :
		rm -rf $(OBJECTS)

fclean : clean
		rm -rf $(NAME)

re : fclean all
