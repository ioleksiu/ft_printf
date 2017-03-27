/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:03:53 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/24 14:38:28 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct			s_pf
{
	int					minus;
	int					zero;
	int					plus;
	int					space;
	int					hash;
	int					dot;
	int					dot_val;
	int					width;
	int					size;
	char				conversion;
	int					i;
	char				*str;
}						t_pf;

uintmax_t				cast_d_u(t_pf *a, va_list ap);
intmax_t				cast_d(t_pf *a, va_list ap);
uintmax_t				cast_du_x(t_pf *a, va_list ap);
uintmax_t				cast_du(t_pf *a, va_list ap);
int						count_num(int a);
int						count_unum(uintmax_t a);
void					f_c(t_pf *a, va_list ap);
void					f_cc(t_pf *a, va_list ap);
void					f_i(t_pf *a, va_list ap);
void					f_d(t_pf *a, va_list ap);
void					f_o(t_pf *a, va_list ap);
void					f_oo(t_pf *a, va_list ap);
void					f_p(t_pf *a, va_list ap);
void					f_proc(char c, t_pf *a);
void					f_s(t_pf *a, va_list ap);
void					f_ss(t_pf *a, va_list ap);
void					f_u(t_pf *a, va_list ap);
void					f_uu(t_pf *a, va_list ap);
void					f_x(t_pf *a, va_list ap);
void					f_xx(t_pf *a, va_list ap);
void					f_dd(t_pf *a, va_list ap);
char					*ft_dot(t_pf *a, char *s);
char					*ft_flags(t_pf *a, char *s);
int						ft_isdigit(int c);
char					*ft_itoa_base(uintmax_t value,
						uintmax_t base, t_pf *a);
char					*ft_itoa_base_1(uintmax_t value,
						uintmax_t base, t_pf *a);
char					*ft_itoa_base4(uintmax_t value,
						uintmax_t base, t_pf *a);
char					*ft_print_text(t_pf *a, char *s);
int						ft_printf(char *format, ...);
void					ft_put_strn(char *s, int i, t_pf *a);
void					ft_put_unbr(uintmax_t n, t_pf *a);
void					ft_putnbr(intmax_t n, t_pf *a);
void					ft_putstr(char const *s, t_pf *a);
char					*ft_size(t_pf *a, char *s);
char					*ft_strchr(const char *s, int c);
size_t					ft_strlen(const char *s);
t_pf					*ft_struct(void);
char					*ft_width(t_pf *a, char *s);
t_pf					*ft_zero_struct(t_pf *a);
char					*parse(char *s, t_pf *a);
void					pf_cast(t_pf *a, va_list ap);
void					put_nchar(char c, int i, t_pf *a);
t_pf					*struct_fill(va_list ap, char *s, t_pf *a);
void					b_n(t_pf *a, va_list ap);
char					*ft_strdup(const char *s1);

#endif
