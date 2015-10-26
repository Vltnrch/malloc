/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 12:46:48 by vroche            #+#    #+#             */
/*   Updated: 2015/01/22 16:34:13 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** long long int to string (char *)
*/

#include "libft.h"

static int	size_lltoa(long long n)
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

static char	*ft_lltoa_part2(void)
{
	char	*ptr;

	if (!(ptr = ft_strnew(20)))
		return (NULL);
	*ptr++ = '-';
	*ptr++ = '9';
	*ptr++ = '2';
	*ptr++ = '2';
	*ptr++ = '3';
	*ptr++ = '3';
	*ptr++ = '7';
	*ptr++ = '2';
	*ptr++ = '0';
	*ptr++ = '3';
	*ptr++ = '6';
	*ptr++ = '8';
	*ptr++ = '5';
	*ptr++ = '4';
	*ptr++ = '7';
	*ptr++ = '7';
	*ptr++ = '5';
	*ptr++ = '8';
	*ptr++ = '0';
	*ptr++ = '8';
	return (ptr - 20);
}

static char	*ft_lltoa_part(long long n)
{
	char	*ptr;

	if (n == 0)
	{
		if (!(ptr = ft_strnew(1)))
			return (NULL);
		*ptr = '0';
		return (ptr);
	}
	return (ft_lltoa_part2());
}

char		*ft_lltoa(long long n)
{
	char		*ptr;
	long long	signe;
	int			size;

	if (n == 0 || n < -9223372036854775807)
		return (ft_lltoa_part(n));
	size = size_lltoa(n);
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
