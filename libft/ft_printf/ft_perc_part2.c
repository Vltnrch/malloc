/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:54:18 by vroche            #+#    #+#             */
/*   Updated: 2015/10/18 15:11:44 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** fonctions for %...d/i, &...o/u/x/X and %...p
*/

#include "ft_printf.h"

void		ft_percdi(t_pf *pf, va_list ap, int height)
{
	long long	d;
	char		*s;

	if (height == R_PF)
		d = (long long)va_arg(ap, int);
	else if (height == HH_PF)
		d = (long long)(signed char)va_arg(ap, int);
	else if (height == H_PF)
		d = (long long)(short)va_arg(ap, int);
	else if (height == L_PF)
		d = (long long)va_arg(ap, long);
	else if (height == LL_PF)
		d = va_arg(ap, long long);
	else if (height == J_PF)
		d = (long long)va_arg(ap, intmax_t);
	else if (height == Z_PF)
		d = (long long)va_arg(ap, size_t);
	else
		return ;
	s = ft_lltoa(d);
	ft_put_di(pf, s);
	free(s);
}

static void	ft_percoux2(t_pf *pf, char c, long long d)
{
	char		*s;
	char		*tmp;

	if (!(s = NULL) && c == 'o')
		s = ft_lltouab(d, 8);
	else if (c == 'u')
		s = ft_lltouab(d, 10);
	else if (c == 'x' || c == 'X')
	{
		s = ft_lltouab(d, 16);
		if (c == 'x')
		{
			tmp = s;
			while (*tmp)
			{
				if (*tmp >= 'A' && *tmp <= 'Z')
					*tmp += 32;
				tmp++;
			}
		}
		ft_put_x(pf, s, c);
	}
	if (c == 'o' || c == 'u')
		ft_put_ou(pf, s);
	free(s);
}

void		ft_percoux(t_pf *pf, va_list ap, int height, char c)
{
	long long	d;

	if (height == R_PF)
		d = (long long)va_arg(ap, unsigned int);
	else if (height == HH_PF)
		d = (long long)(unsigned char)va_arg(ap, int);
	else if (height == H_PF)
		d = (long long)(unsigned short)va_arg(ap, int);
	else if (height == L_PF)
		d = (long long)va_arg(ap, unsigned long);
	else if (height == LL_PF)
		d = va_arg(ap, long long);
	else if (height == J_PF)
		d = (long long)va_arg(ap, uintmax_t);
	else if (height == Z_PF)
		d = (long long)va_arg(ap, size_t);
	else
		return ;
	ft_percoux2(pf, c, d);
}

void		ft_percp(t_pf *pf, va_list ap)
{
	long long	d;
	char		*s;
	char		*s2;

	d = va_arg(ap, long long);
	s = ft_lltouab(d, 16);
	s2 = s;
	while (*s2)
	{
		if (*s2 >= 'A' && *s2 <= 'Z')
			*s2 += 32;
		s2++;
	}
	ft_put_p(pf, s);
	free(s);
}
