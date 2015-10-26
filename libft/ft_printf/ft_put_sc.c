/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 12:09:52 by vroche            #+#    #+#             */
/*   Updated: 2015/03/11 17:34:54 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Fonction to put string and all precisions to printf buff
** here only for %...s and also for %...c
*/

void	ft_put_s(t_pf *pf, char *s)
{
	t_optp	*optp;
	int		i;

	optp = pf->optp;
	i = ft_strlen(s);
	if (optp->bd != 0 && optp->l == 0 && optp->z == 1 && i < optp->bd)
		ft_strcharpf(pf, '0', optp->bd - i);
	else if (optp->bd != 0 && optp->l == 0 && i < optp->bd && \
			(optp->ad >= i || optp->ad == -1))
		ft_strcharpf(pf, ' ', optp->bd - i);
	else if (optp->bd != 0 && optp->l == 0 && optp->ad > 0 \
				&& optp->bd > optp->ad)
		ft_strcharpf(pf, ' ', optp->ad > i ? \
					optp->bd - i : optp->bd - optp->ad);
	if (optp->ad == -1 || i <= optp->ad)
		ft_strncpypf(pf, s, i);
	else if (i > optp->ad)
		ft_strncpypf(pf, s, optp->ad);
	if (optp->bd != 0 && optp->l == 1 && i < optp->bd && \
		(optp->ad >= i || optp->ad == -1))
		ft_strcharpf(pf, ' ', optp->bd - i);
	else if (optp->bd != 0 && optp->l == 1 && optp->ad > 0 \
		&& optp->bd > optp->ad)
		ft_strcharpf(pf, ' ', optp->ad > i ? \
					optp->bd - i : optp->bd - optp->ad);
}

void	ft_put_c(t_pf *pf, char c)
{
	t_optp	*optp;

	optp = pf->optp;
	if (optp->bd > 1 && optp->z == 0 && optp->l == 0)
		ft_strcharpf(pf, ' ', optp->bd - 1);
	else if (optp->bd > 1 && optp->z == 1 && optp->l == 0)
		ft_strcharpf(pf, '0', optp->bd - 1);
	pf->cnt++;
	pf->rcnt++;
	*(pf->str)++ = c;
	if (optp->l == 1 && optp->bd > 1)
		ft_strcharpf(pf, ' ', optp->bd - 1);
}
