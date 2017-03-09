/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:03:53 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/02/19 15:03:55 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

typedef struct 							s_pf
{
	int									minus;
	int									zero;
	int									plus;
	int									space;
	int									hash;
	int									dot;
	int									dot_val;
	int									width;
	int									size;
	char								conversion;
    int                                 i;
}										t_pf;

char									*ft_flags(t_pf *a, char *s);
char									*ft_width(t_pf *a, char *s);
char									*ft_dot(t_pf *a, char *s);
char									*ft_size(t_pf *a, char *s);
t_pf									*struct_fill(va_list ap, char *s, t_pf *a);
t_pf									*ft_struct(void);
void									ft_print_struct(t_pf *a);
int										ft_isdigit(int c);
char									*ft_print_text(t_pf *a, char *s);
int                                     ft_printf(char *format, ... );
void                                    f_proc(char c, t_pf *a);
void                                    pf_cast(t_pf *a, va_list ap);
void	                                ft_putnbr(intmax_t n, t_pf *a);/* chage soon*/
char									*ft_strchr(const char *s, int c);
size_t									ft_strlen(const char *s);
intmax_t                                cast_d(t_pf *a, va_list ap);