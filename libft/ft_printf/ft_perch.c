/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:16:24 by vroche            #+#    #+#             */
/*   Updated: 2015/03/10 12:50:28 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** fonction who return number of height
*/

#include "ft_printf.h"

static int	ft_perchh(t_pf *pf)
{
	pf->format++;
	if (*(pf->format) == 'h')
	{
		pf->format++;
		return (HH_PF);
	}
	return (H_PF);
}

static int	ft_perchl(t_pf *pf)
{
	pf->format++;
	if (*(pf->format) == 'l')
	{
		pf->format++;
		return (LL_PF);
	}
	return (L_PF);
}

int			ft_perch(t_pf *pf)
{
	int	r;
	int	r2;

	r = R_PF;
	if (*(pf->format) == 'h')
		r = ft_perchh(pf);
	else if (*(pf->format) == 'l')
		r = ft_perchl(pf);
	else if (*(pf->format) == 'j')
	{
		pf->format++;
		r = J_PF;
	}
	else if (*(pf->format) == 'z')
	{
		pf->format++;
		r = Z_PF;
	}
	if (r != R_PF)
		return ((r2 = ft_perch(pf)) > r ? r2 : r);
	return (R_PF);
}
