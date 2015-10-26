/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:56:28 by vroche            #+#    #+#             */
/*   Updated: 2015/03/04 15:39:39 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Fonction to put string and all precisions to printf buff
** here only for %...d/i/o/u/x/p
*/

void		ft_put_p(t_pf *pf, char *s)
{
	int		i;

	i = ft_strlen(s);
	if (pf->optp->ad > 0 && pf->optp->ad > i)
	{
		if (pf->optp->bd > pf->optp->ad)
			ft_strcharpf(pf, ' ', pf->optp->ad > 0 \
				? pf->optp->bd - pf->optp->ad : pf->optp->bd - i);
	}
	else if (pf->optp->m == 0 && pf->optp->z == 0 && \
		pf->optp->l == 0 && pf->optp->s == 0 && pf->optp->bd > 0 \
		&& pf->optp->bd > (i + 2))
		ft_strcharpf(pf, ' ', pf->optp->bd - i - 2);
	ft_strncpypf(pf, "0x", 2);
	if (pf->optp->ad > 0 && pf->optp->ad > i && (pf->optp->d == 1 \
		|| pf->optp->ad > pf->optp->bd))
		ft_strcharpf(pf, '0', pf->optp->ad - i);
	if (pf->optp->ad != 0 || (pf->optp->ad == 0 && pf->optp->d == 1))
		ft_strncpypf(pf, s, i);
	if (pf->optp->l == 1 && pf->optp->bd > (i + 2))
		ft_strcharpf(pf, ' ', pf->optp->bd - i - 2);
	if (pf->optp->ad <= pf->optp->bd && ((pf->optp->z == 1 \
		&& pf->optp->bd > (i + 2)) || (pf->optp->ad > 0 && pf->optp->ad > i)))
		ft_strcharpf(pf, '0', pf->optp->z == 1 ? pf->optp->bd - i - 2 \
											: pf->optp->ad - i);
}
