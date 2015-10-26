/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percopt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 15:50:37 by vroche            #+#    #+#             */
/*   Updated: 2015/03/11 17:30:23 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Fonction to init struct printf option
** Fonction to convert '*' or arg to int for precision
** Fonction to put options in struct
*/

#include "ft_printf.h"

void		ft_percopt_init(t_optp *optp)
{
	optp->d = 0;
	optp->z = 0;
	optp->l = 0;
	optp->m = 0;
	optp->s = 0;
	optp->bd = 0;
	optp->ad = -1;
}

static void	ft_percpre3(t_pf *pf, t_optp *optp, va_list ap)
{
	optp->ad = (*(pf->format) == '*' ? va_arg(ap, int) : ft_atoi(pf->format));
	if (optp->ad < 0)
		optp->ad = -1;
	while ((*(pf->format) >= '0' && *(pf->format) <= '9') \
			|| *(pf->format) == '*')
		pf->format++;
}

static void	ft_percpre2(t_pf *pf, t_optp *optp, va_list ap)
{
	while (*(pf->format) >= '0' && *(pf->format) <= '9')
		pf->format++;
	if (*(pf->format) == '*')
		ft_percpre(pf, optp, ap);
	if (*(pf->format) == '.')
	{
		pf->format++;
		if (*(pf->format) == '.')
		{
			while ((*(pf->format) >= '0' && *(pf->format) <= '9') \
				|| *(pf->format) == '.')
				pf->format++;
			return ;
		}
		ft_percpre3(pf, optp, ap);
	}
}

void		ft_percpre(t_pf *pf, t_optp *optp, va_list ap)
{
	if (!(*(pf->format) >= '1' && *(pf->format) <= '9') && *(pf->format) != '*')
	{
		if (*(pf->format) == '.')
		{
			pf->format++;
			ft_percpre3(pf, optp, ap);
		}
		return ;
	}
	optp->bd = ((*(pf->format) == '*') ? va_arg(ap, int) \
										: ft_atoi(pf->format));
	if (optp->bd < 0)
	{
		optp->l = 1;
		optp->bd = -optp->bd;
	}
	if (*(pf->format) == '*')
	{
		pf->format++;
		if (*(pf->format) >= '0' && *(pf->format) <= '9')
			ft_percpre(pf, optp, ap);
	}
	ft_percpre2(pf, optp, ap);
}

void		ft_percopt(t_pf *pf, t_optp *optp, va_list ap)
{
	if (*(pf->format) == '#')
		optp->d = 1;
	else if (*(pf->format) == '0')
		optp->z = 1;
	else if (*(pf->format) == '-')
		optp->l = 1;
	else if (*(pf->format) == '+')
		optp->m = 1;
	else if (*(pf->format) == ' ')
		optp->s = 1;
	else
		return ;
	pf->format++;
	ft_percopt(pf, optp, ap);
}
