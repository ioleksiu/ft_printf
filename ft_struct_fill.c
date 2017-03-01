/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:10:34 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/02/19 15:10:36 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_flags(t_pf *a, char *s)
{
		if (*s == '-')
			a->minus = 1;
		else if (*s == ' ')
			a->space = 1;
		else if (*s == '+')
			a->plus = 1;
		else if (*s == '#')
			a->hash = 1;
		else if (*s == '0')
			a->zero = 1;
		else
			return (s);
		s+=1;
		return (s);
}

char	*ft_width(t_pf *a, char *s)
{
	if (*s > '0' && *s <= '9' && *(s - 1) != '.')
	{
			a->width = *s - '0';
			s++;
			while (*s <= '9' && *s >= '0')
			{
				a->width = a->width * 10 + *s - '0';
				s++;
			}
	}
	return (s);
}

char	*ft_dot(t_pf *a, char *s)
{
	if (*s == '.' && ft_isdigit(*(s + 1)))
	{
			a->dot = 1;
			a->dot_val = *(s + 1) - '0';
			s++;
			while(*(s + 1) <= '9' && *(s + 1) >= '0') 
			{
				a->dot_val = a->dot_val * 10 + *(s + 1) - '0';
				s++;
			}
			if (*s >='0' && *s <= '9')
            {
                s++;
                return (s);
            }
            return(s+1);
	}
    if (*s == '.' && !(ft_isdigit(*(s + 1))))
    {
        a->dot = 0;
        a->dot_val = 0;
        return(s+1);
    }
	return(s);
}

char	*ft_size(t_pf *a ,char *s)
{
	if (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z')
	{
		if (*s == 'h' && *(s + 1) != 'h' && *(s - 1) != 'h')
			a->size = 2;
		if (*s == 'h' && ((*(s + 1) == 'h' || *(s - 1) == 'h')))
		{
			a->size = 1;
			s++;
		}
		if (*s == 'l' && *(s + 1) != 'l' && *(s - 1) != 'l')
			a->size = 3;
		if (*s == 'l' && *(s + 1) == 'l')
		{
			a->size = 4;
			s++;
		}
		if (*s == 'j')
			a->size = 5;
		if (*s == 'z')
			a->size = 6;
		s++;
	}
	return (s);
}

t_pf *ft_zero_struct(t_pf *a)
{
    a->minus = 0;
    a->zero = 0;
    a->plus = 0;
    a->space = 0;
    a->hash = 0;
    a->dot = 0;
    a->dot_val = 0;
    a->width = 0;
    a->size = 0;
    a->conversion = '0';
    return (a);
}

char *parse(char *s, t_pf *a)
{
    s = ft_flags(a, s);
    s = ft_width(a, s);
    s = ft_dot(a, s);
    s = ft_size(a, s);
    if (strchr("sSpdDioOuUxXcC", *s) && *s)/*change to ft_strchr */
    {
        a->conversion = *s;
        s++;
    }
    return (s);
}

t_pf	*struct_fill(va_list ap, char *s, t_pf *a)
{
    while (*s != '\0')
    {
        s = ft_print_text(a, s);
        if (!(*s))
            break;
        while (*s && a->conversion == '0' /*&& *s != '%'*/)
        {
            if (strchr("hljz -+#01234567.89tsSpdDioOuUxXcC", *s) == NULL
                && a->conversion == '0')
            {
                a->conversion = 'c';
                f_proc(*s,a);
                ft_zero_struct(a);
                s++;
                break;
            }
            s = parse(s,a);
        }
         pf_cast(a, ap);
        if (strchr("sSpdDioOuUxXcC", *s) && *(s-1) == '%')/* A , a etc. */
            s++;
        ft_zero_struct(a);
    }
	return (a);
}

