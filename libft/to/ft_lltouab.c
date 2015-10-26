/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltouab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 12:54:25 by vroche            #+#    #+#             */
/*   Updated: 2015/01/22 16:34:18 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** long long int to unsigned long long int to string (char *)
** with base conversion choice
*/

#include "libft.h"

static int	size_lltouab(unsigned long long n, unsigned int base)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		size++;
		n /= base;
	}
	return (size);
}

static char	*ft_lltouab_part(void)
{
	char	*ptr;

	if (!(ptr = ft_strnew(1)))
		return (NULL);
	*ptr = '0';
	return (ptr);
}

char		*ft_lltouab(long long n, unsigned int base)
{
	char				*ptr;
	int					size;
	unsigned long long	d;
	int					m;

	d = (unsigned long long)n;
	if (d == 0)
		return (ft_lltouab_part());
	size = size_lltouab(d, base);
	if (!(ptr = ft_strnew(size)))
		return (NULL);
	ptr += size - 1;
	while (d > 0)
	{
		m = d % base;
		if (m > 9)
			*ptr-- = ('7' + m);
		else
			*ptr-- = ('0' + m);
		d /= base;
	}
	return (ptr + 1);
}
