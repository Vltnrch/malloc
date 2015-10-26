/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:52:36 by vroche            #+#    #+#             */
/*   Updated: 2014/11/10 13:53:51 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*d;

	d = s;
	if (s == NULL)
		return (NULL);
	while (n)
	{
		*d++ = (unsigned char)c;
		n--;
	}
	return (s);
}
