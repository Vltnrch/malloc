/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:11:46 by vroche            #+#    #+#             */
/*   Updated: 2015/03/13 14:22:09 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** fonction to manage all %... conversions
*/

#include "ft_printf.h"

static void	ft_perc2(t_pf *pf, va_list ap, int height)
{
	if (*(pf->format) == 'o' || *(pf->format) == 'u' \
		|| *(pf->format) == 'x' || *(pf->format) == 'X')
		ft_percoux(pf, ap, height, *(pf->format));
	else if (*(pf->format) == 'O')
		ft_percoux(pf, ap, L_PF, 'o');
	else if (*(pf->format) == 'U')
		ft_percoux(pf, ap, L_PF, 'u');
	else if (*(pf->format) == 'c')
		ft_percc(pf, ap, height);
	else if (*(pf->format) == 'C')
		ft_percc(pf, ap, L_PF);
	else if (*(pf->format) == 'p')
		ft_percp(pf, ap);
	else if (pf->optp->bd > 0)
		ft_put_c(pf, *(pf->format));
	else
		pf->format--;
}

void		ft_perc(t_pf *pf, va_list ap)
{
	int		height;

	pf->format++;
	ft_percopt_init(pf->optp);
	ft_percopt(pf, pf->optp, ap);
	ft_percpre(pf, pf->optp, ap);
	ft_percopt(pf, pf->optp, ap);
	height = ft_perch(pf);
	ft_percopt(pf, pf->optp, ap);
	if (*(pf->format) == '%')
		ft_put_c(pf, *(pf->format));
	else if (*(pf->format) == 's')
		ft_percs(pf, ap, height);
	else if (*(pf->format) == 'S')
		ft_percs(pf, ap, L_PF);
	else if (*(pf->format) == 'd' || *(pf->format) == 'i')
		ft_percdi(pf, ap, height);
	else if (*(pf->format) == 'D')
		ft_percdi(pf, ap, L_PF);
	else
		ft_perc2(pf, ap, height);
	pf->format++;
}
