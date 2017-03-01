/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:58:33 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/02/19 16:58:35 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_text(t_pf *a, char *s)
{
	while (*s)
	{
		if (*s == '%' && *(s+1) == '%')
		{
			write(1, s , 1);
            a->i++;
			if (*(s+2) != '\0')
				s+=2;
			else
				return(s+=2);
		}
		if (*s == '%' && *(s + 1) != '%')
			return (s+=1);
		write(1, s , 1);
        a->i++;
		s++;
	}

	if (*s)
	    return(s+=1);
    return (s);

}
/* "%%%-+0d" fix it*/
/*
sunday > ./a.out "Hello%%%0+232#43-234-.3434#d "
Hello%
minus 0
zero 1
plus 0
space 0
hash 0
dot 1
dot_val 3434
width 234
size : none
size 0
conversion d
~/sunday >

*/