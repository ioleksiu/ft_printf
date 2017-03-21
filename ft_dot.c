/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:06:41 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/21 17:07:20 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dot(t_pf *a, char *s)
{
    if (*s == '.' && (!(ft_isdigit(*(s + 1))) || *(s + 1) == '0')) /* || added */
    {
        a->dot = 1;
        a->dot_val = -1;/* changed 0 to -1 */
        return(s+1);
    }

	else if (*s == '.' && ft_isdigit(*(s + 1)))
	{
		a->dot = 1;
		a->dot_val = *(s + 1) - '0';
		s++;
		while(*(s + 1) <= '9' && *(s + 1) >= '0') /* >= 0*/
		{
			a->dot_val = a->dot_val * 10 + *(s + 1) - '0';
			s++;
		}
		if (*s >'0' && *s <= '9')/* >= 0 */
		{
			s++;
			return (s);
		}
		return(s+1);
	}

    //if (*s == '.' && (!(ft_isdigit(*(s + 1))) || *(s + 1) == 0)) /* || added */
    //{
	//   a->dot = 1;
	// a->dot_val = -1;/* changed 0 to -1 */
	//return(s+1);
    //}
    //*/
    else
		return(s);
}
