/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:21:07 by vroche            #+#    #+#             */
/*   Updated: 2015/03/11 17:36:05 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Fonction to put string and all precisions to printf buff
** here only for %...x
*/

static void	ft_put_x3(t_pf *pf, char *s, int i)
{
	if (((pf->optp->ad > 0 && pf->optp->ad > i) || \
		(pf->optp->z == 1 && pf->optp->bd > (i + 2))) && \
		pf->optp->d == 1 && pf->optp->l == 0)
		ft_strcharpf(pf, '0', pf->optp->z == 1 ? pf->optp->bd - i - 2 : \
												pf->optp->ad - i);
	if (pf->optp->ad != 0)
		ft_strncpypf(pf, s, i);
	if ((pf->optp->z == 0 || (pf->optp->z == 1 && pf->optp->d == 1)) && \
		pf->optp->l == 1 && pf->optp->bd > i)
		ft_strcharpf(pf, ' ', (pf->optp->d == 1 && \
						(*s != '0' || i != 1 || pf->optp->ad == 0)) \
						? pf->optp->bd - i - 2 : pf->optp->bd - i);
	else if (pf->optp->d == 1 && pf->optp->z == 1 && pf->optp->l == 1 && \
			pf->optp->bd > (i + 2))
		ft_strcharpf(pf, '0', pf->optp->bd - i - 2);
}

static void	ft_put_x2(t_pf *pf, char *s, char c, int i)
{
	if (pf->optp->ad > 0 && pf->optp->d == 0 && pf->optp->ad > i)
		ft_strcharpf(pf, '0', pf->optp->d == 1 && (*s != '0' || i != 1 || \
			pf->optp->ad == 0) ? pf->optp->ad - i - 1 : pf->optp->ad - i);
	if (pf->optp->d == 1 && (*s != '0' || i != 1 || pf->optp->ad == 0))
	{
		if (c == 'X' && *s != '0')
			ft_strncpypf(pf, "0X", 2);
		else if (c == 'x' && *s != '0')
			ft_strncpypf(pf, "0x", 2);
	}
	ft_put_x3(pf, s, i);
}

void		ft_put_x(t_pf *pf, char *s, char c)
{
	int		i;

	i = ft_strlen(s);
	if (pf->optp->z == 1 && pf->optp->d == 0 && pf->optp->bd > i \
		&& pf->optp->l == 0 && pf->optp->ad <= 0)
		ft_strcharpf(pf, '0', pf->optp->bd - i);
	if ((pf->optp->m == 0 && pf->optp->z == 0 \
		&& pf->optp->l == 0 && pf->optp->s == 0 && pf->optp->bd > 0 && \
		pf->optp->bd > i && pf->optp->bd > pf->optp->ad) || pf->optp->ad > 0)
	{
		if (pf->optp->bd > pf->optp->ad && pf->optp->ad > i)
			ft_strcharpf(pf, ' ', pf->optp->ad > 0 \
				? pf->optp->bd - pf->optp->ad : pf->optp->bd - i);
		else if (pf->optp->bd > pf->optp->ad && pf->optp->ad < i)
			ft_strcharpf(pf, ' ', (pf->optp->d == 1 && \
						(*s != '0' || i != 1 || pf->optp->ad == 0)) \
						? pf->optp->bd - i - 2 : pf->optp->bd - i);
		if (pf->optp->ad == 0)
			ft_strcharpf(pf, ' ', 1);
	}
	ft_put_x2(pf, s, c, i);
}
