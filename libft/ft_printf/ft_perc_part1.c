/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:52:36 by vroche            #+#    #+#             */
/*   Updated: 2015/10/18 15:11:50 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** fonctions for %...s and %...c
*/

#include "ft_printf.h"

void	ft_percs(t_pf *pf, va_list ap, int height)
{
	void	*s;

	if (height == R_PF)
	{
		s = va_arg(ap, char *);
		if (s != NULL && pf->optp->ad != 0)
			ft_put_s(pf, (char *)s);
		else if (pf->optp->ad != 0)
			ft_strncpypf(pf, "(null)", 6);
		else if (pf->optp->ad == 0)
			ft_put_s(pf, "");
	}
	else if (height == L_PF)
	{
		s = va_arg(ap, wchar_t *);
		if (s != NULL && pf->optp->ad != 0)
			ft_put_ss(pf, (wchar_t *)s);
		else if (pf->optp->ad != 0)
			ft_strncpypf(pf, "(null)", 6);
		else if (pf->optp->ad == 0)
			ft_put_s(pf, "");
	}
	else
		return ;
}

void	ft_percc(t_pf *pf, va_list ap, int height)
{
	int		d;
	wint_t	dd;
	char	*s;

	if (height == R_PF)
	{
		d = va_arg(ap, int);
		ft_put_c(pf, (char)d);
	}
	else if (height == L_PF)
	{
		dd = va_arg(ap, wint_t);
		if (!(s = ft_strnew(4)))
			return ;
		d = ft_witoa(s, dd);
		ft_strncpypf(pf, s + (4 - d), d);
		free(s);
	}
	else
		return ;
}
