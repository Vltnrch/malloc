/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 22:05:45 by vroche            #+#    #+#             */
/*   Updated: 2014/11/08 16:24:58 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	char		*s;
	char		*temp;

	d = (char *)dest;
	s = (char *)src;
	if (d == NULL || s == NULL)
		return (0);
	if (!(temp = ft_strnew(ft_strlen(s))))
		return (NULL);
	temp = ft_strcpy(temp, s);
	while (n)
	{
		*d++ = *temp++;
		n--;
	}
	return (dest);
}
