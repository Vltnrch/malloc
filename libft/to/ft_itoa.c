/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:50:55 by vroche            #+#    #+#             */
/*   Updated: 2014/11/09 19:25:54 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_itoa(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	else if (n == 0)
		size++;
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static char	*ft_itoa_part(int n)
{
	char	*ptr;

	if (n == 0)
	{
		if (!(ptr = ft_strnew(1)))
			return (NULL);
		*ptr = '0';
		return (ptr);
	}
	if (!(ptr = ft_strnew(11)))
		return (NULL);
	*ptr++ = '-';
	*ptr++ = '2';
	*ptr++ = '1';
	*ptr++ = '4';
	*ptr++ = '7';
	*ptr++ = '4';
	*ptr++ = '8';
	*ptr++ = '3';
	*ptr++ = '6';
	*ptr++ = '4';
	*ptr++ = '8';
	return (ptr - 11);
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		signe;
	int		size;

	if (n == 0 || n == -2147483648)
		return (ft_itoa_part(n));
	size = size_itoa(n);
	if (!(ptr = ft_strnew(size)))
		return (NULL);
	ptr += size - 1;
	if ((signe = n) < 0)
		n = -n;
	while (n > 0)
	{
		*ptr-- = ('0' + (n % 10));
		n /= 10;
	}
	if (signe < 0)
		*ptr-- = '-';
	return (ptr + 1);
}
