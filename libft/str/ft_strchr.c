/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:12:17 by vroche            #+#    #+#             */
/*   Updated: 2014/11/06 18:20:16 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*d;

	d = (char *)s;
	if (c == 0)
		return (d + ft_strlen(d));
	while (*d)
	{
		if (*d == (char)c)
			return (d);
		d++;
	}
	return (NULL);
}
