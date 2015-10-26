/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 12:53:59 by vroche            #+#    #+#             */
/*   Updated: 2015/03/13 14:33:07 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Principal fonction and his init
** ft_dprintf / ft_printf / ft_vdprintf / ft_vprintf
*/

#include "ft_printf.h"

static int	ft_pfinit(t_pf **pf, const char *format, int fd)
{
	if (!(*pf = (t_pf *)malloc(sizeof(t_pf))))
		return (-1);
	if (!((*pf)->optp = (t_optp *)malloc(sizeof(t_optp))))
		return (-1);
	if (!((*pf)->str = malloc(BUFF_PF + 1)))
		return (-1);
	(*pf)->cnt = 0;
	(*pf)->tmp = (*pf)->str;
	(*pf)->rcnt = 0;
	(*pf)->format = format;
	(*pf)->fd = fd;
	return (0);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	int		r;
	va_list	*ap;

	if (!(ap = (va_list *)malloc(sizeof(va_list))))
		return (-1);
	va_start(*ap, format);
	r = ft_vdprintf(fd, format, *ap);
	va_end(*ap);
	free(ap);
	return (r);
}

int			ft_printf(const char *format, ...)
{
	int		r;
	va_list	*ap;

	if (!(ap = (va_list *)malloc(sizeof(va_list))))
		return (-1);
	va_start(*ap, format);
	r = ft_vprintf(format, *ap);
	va_end(*ap);
	free(ap);
	return (r);
}

int			ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_pf	*pf;
	int		rcnt;

	if (ft_pfinit(&pf, format, fd) == -1)
		return (-1);
	while (*(pf->format) != '\0')
	{
		if (pf->cnt == BUFF_PF)
			ft_pbuff(pf);
		else if (*(pf->format) == '%')
			ft_perc(pf, ap);
		else
		{
			*(pf->str)++ = *(pf->format)++;
			pf->cnt++;
			pf->rcnt++;
		}
	}
	if (pf->cnt != 0)
		ft_pbuff(pf);
	rcnt = pf->rcnt;
	ft_clear_pbuff(&pf);
	return (rcnt);
}

int			ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}
