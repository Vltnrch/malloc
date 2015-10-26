/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:44:33 by vroche            #+#    #+#             */
/*   Updated: 2015/03/04 13:01:47 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** wint to char *
** wchar_t * to string (char*)
** return a int pointer of bytes copied for every character
** witoa need char * with 4 bytes allocated
*/

#include "ft_printf.h"

int				ft_witoa(char *dest, wint_t src)
{
	if (src <= 0x7F)
	{
		dest[3] = (char)src;
		return (1);
	}
	dest[3] = (src & ((1 << 6) - 1)) | 1 << 7;
	if (src <= 0x7FF)
	{
		dest[2] = (src >> 6 | 3 << 6);
		return (2);
	}
	dest[2] = ((src >> 6) & ((1 << 6) - 1)) | 1 << 7;
	if (src <= 0xFFFF)
	{
		dest[1] = (src >> 12 | 7 << 5);
		return (3);
	}
	dest[1] = ((src >> 12) & ((1 << 6) - 1)) | 1 << 7;
	if (src <= 0x10FFFF)
	{
		dest[0] = (src >> 18 | 15 << 4);
		return (4);
	}
	return (-1);
}

static size_t	ft_wcharlen(wchar_t *s)
{
	size_t	i;
	char	*tmp;

	if (!(tmp = ft_strnew(4)))
		return (-1);
	i = 0;
	while (*s)
		i += ft_witoa(tmp, (wint_t)*s++);
	free(tmp);
	return (i);
}

static int		*ft_wctoa2(char **dest, wchar_t *src, int *nb, char *tmp)
{
	int		*nbtmp;
	int		r;
	char	*rdest;

	nbtmp = nb;
	rdest = NULL;
	r = 0;
	if (!(rdest = ft_strnew(r)))
		return (NULL);
	while (*src)
	{
		if ((*nb = ft_witoa(tmp, (wint_t)*src)) == -1)
			return (NULL);
		if (!(rdest = ft_realloc((void *)rdest, r, r + *nb)))
			return (NULL);
		ft_memcpy((void *)rdest + r, tmp + (4 - *nb), *nb);
		ft_bzero(tmp, 4);
		src++;
		r += *nb++;
	}
	*nb = 0;
	*dest = rdest;
	free(tmp);
	return (nbtmp);
}

int				*ft_wctoa(char **dest, wchar_t *src)
{
	int		*nb;
	char	*tmp;

	if (!(tmp = ft_strnew(4)))
		return (NULL);
	if (!(nb = (int *)malloc(sizeof(int) * (ft_wcharlen(src) + 1))))
		return (NULL);
	return (ft_wctoa2(dest, src, nb, tmp));
}
