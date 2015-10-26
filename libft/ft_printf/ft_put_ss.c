/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 12:40:58 by vroche            #+#    #+#             */
/*   Updated: 2015/03/13 12:58:33 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Fonction to put string and all precisions to printf buff
** here only for %...S
*/

static void	ft_put_ss3(t_pf *pf, char *str, int *i)
{
	int		*itmp;
	int		len;

	itmp = i;
	len = 0;
	while ((pf->optp->ad == -1 || (len += *i) <= pf->optp->ad) && *str != 0)
	{
		ft_strncpypf(pf, str, *i);
		str += *i++;
	}
	i = itmp;
	len = 0;
	if (pf->optp->l == 1)
	{
		while (*i != 0)
			len += *i++;
		ft_strcharpf(pf, ' ', pf->optp->bd - len);
	}
}

static void	ft_put_ss2(t_pf *pf, char *str, int *i, int len)
{
	int		*itmp;

	itmp = i;
	if (pf->optp->bd != 0 && pf->optp->z == 1 && len < pf->optp->bd)
		ft_strcharpf(pf, '0', pf->optp->bd - len);
	else if (pf->optp->bd != 0 && pf->optp->l == 0)
	{
		len = 0;
		if (pf->optp->ad > 0 && pf->optp->bd > pf->optp->ad)
		{
			while (*i != 0 && (len + *i) <= pf->optp->ad)
				len += *i++;
			ft_strcharpf(pf, ' ', pf->optp->bd - len);
		}
		else if (pf->optp->bd > pf->optp->ad)
		{
			while (*i != 0 && (len + *i) <= pf->optp->bd)
				len += *i++;
			ft_strcharpf(pf, ' ', pf->optp->bd - len);
		}
	}
	ft_put_ss3(pf, str, itmp);
}

void		ft_put_ss(t_pf *pf, wchar_t *s)
{
	char	*str;
	int		*i;
	int		*itmp;
	int		len;

	if (!(i = ft_wctoa(&str, s)))
		return ;
	itmp = i;
	len = 0;
	while (*i != 0)
		len += *i++;
	ft_put_ss2(pf, str, itmp, len);
	free(itmp);
	free(str);
}
