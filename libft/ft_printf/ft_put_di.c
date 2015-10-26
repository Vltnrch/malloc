/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:05:58 by vroche            #+#    #+#             */
/*   Updated: 2015/03/11 17:32:48 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Fonction to put string and all precisions to printf buff
** here only for %...d/i
*/

static void	ft_put_di4(t_pf *pf, char *s, int i)
{
	if (*s != '0' || pf->optp->ad != 0 \
		|| (pf->optp->ad == 0 && pf->optp->d == 1))
		ft_strncpypf(pf, s, i);
	if (pf->optp->l == 1 && pf->optp->bd > i && pf->optp->bd > pf->optp->ad)
		ft_strcharpf(pf, ' ', pf->optp->ad > 0 \
					? pf->optp->bd - pf->optp->ad : pf->optp->bd - i);
}

static void	ft_put_di3(t_pf *pf, char *s, int i)
{
	if (pf->optp->z == 1 && pf->optp->bd > i && pf->optp->l == 0 && \
		(pf->optp->ad <= 0 || (pf->optp->ad != 0 && *s != '0')))
	{
		if (*s == '-')
		{
			ft_strncpypf(pf, s++, 1);
			i--;
			if (pf->optp->bd > 0)
				pf->optp->bd--;
		}
		ft_strcharpf(pf, (pf->optp->d == 1) ? ' ' : '0', \
			(pf->optp->bd > pf->optp->ad && pf->optp->ad > 0) \
			? pf->optp->bd - pf->optp->ad : pf->optp->bd - i);
	}
	else if (pf->optp->ad > 0 && pf->optp->ad > i)
	{
		if (*s == '-')
		{
			ft_strncpypf(pf, s++, 1);
			i--;
		}
		ft_strcharpf(pf, '0', pf->optp->d == 1 && (*s != '0' || i != 1 \
			|| pf->optp->ad == 0) ? pf->optp->ad - i - 1 : pf->optp->ad - i);
	}
	ft_put_di4(pf, s, i);
}

static void	ft_put_di2(t_pf *pf, char *s, int i)
{
	if (pf->optp->m == 1 && *s != '-')
		ft_strncpypf(pf, "+", 1);
	else if (pf->optp->s == 1 && *s != '-')
		ft_strncpypf(pf, " ", 1);
	ft_put_di3(pf, s, i);
}

void		ft_put_di(t_pf *pf, char *s)
{
	int		i;

	i = ft_strlen(s);
	if ((pf->optp->m == 1 || pf->optp->s == 1) && *s != '-' && pf->optp->bd > 0)
		pf->optp->bd--;
	if (pf->optp->l == 0 && ((pf->optp->z == 0 && pf->optp->bd > 0 && \
		pf->optp->bd > i && pf->optp->bd > pf->optp->ad) || \
		(pf->optp->ad > 0 && pf->optp->bd > i)))
	{
		if (pf->optp->bd > pf->optp->ad && pf->optp->ad > i)
		{
			if (*s == '-')
				ft_strcharpf(pf, ' ', pf->optp->ad > 0 \
					? pf->optp->bd - pf->optp->ad - 1 : pf->optp->bd - 1);
			else
				ft_strcharpf(pf, ' ', pf->optp->ad > 0 \
					? pf->optp->bd - pf->optp->ad : pf->optp->bd - i);
		}
		else if (pf->optp->bd > pf->optp->ad && pf->optp->ad < i)
			ft_strcharpf(pf, ' ', pf->optp->bd - i);
		if (pf->optp->ad == 0)
			ft_strcharpf(pf, ' ', 1);
	}
	ft_put_di2(pf, s, i);
}
