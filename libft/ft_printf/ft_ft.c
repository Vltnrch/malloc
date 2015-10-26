/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 14:15:17 by vroche            #+#    #+#             */
/*   Updated: 2015/03/13 14:22:24 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** fonction to add string with n char to printf's buff
** strncpy fonction modified for printf
** display fonction
*/

#include "ft_printf.h"

void	ft_strcharpf(t_pf *pf, char c, size_t n)
{
	while (n > 0)
	{
		if (pf->cnt == BUFF_PF)
			ft_pbuff(pf);
		*(pf->str)++ = c;
		pf->cnt++;
		pf->rcnt++;
		n--;
	}
}

void	ft_strncpypf(t_pf *pf, char *src, size_t n)
{
	while (n > 0)
	{
		if (pf->cnt == BUFF_PF)
			ft_pbuff(pf);
		*(pf->str)++ = *src++;
		pf->cnt++;
		pf->rcnt++;
		n--;
	}
}

int		ft_pbuff(t_pf *pf)
{
	write(pf->fd, pf->tmp, pf->cnt);
	free(pf->tmp);
	if (!(pf->str = (char *)malloc(BUFF_PF + 1)))
		return (-1);
	pf->cnt = 0;
	pf->tmp = pf->str;
	return (0);
}

void	ft_clear_pbuff(t_pf **pf)
{
	free((*pf)->tmp);
	free((*pf)->optp);
	free(*pf);
}
