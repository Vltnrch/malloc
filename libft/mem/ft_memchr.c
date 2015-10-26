/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:05:48 by vroche            #+#    #+#             */
/*   Updated: 2014/11/09 16:06:51 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;

	ss = s;
	while (n)
	{
		if (*ss == (unsigned char)c)
		{
			return ((void *)ss);
		}
		ss++;
		n--;
	}
	return (NULL);
}
