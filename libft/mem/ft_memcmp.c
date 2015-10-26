/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:20:05 by vroche            #+#    #+#             */
/*   Updated: 2014/11/09 17:21:59 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	d1;
	unsigned char	d2;

	while (n)
	{
		d1 = *(unsigned char *)s1;
		d2 = *(unsigned char *)s2;
		if (d1 != d2)
		{
			return (d1 - d2);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
