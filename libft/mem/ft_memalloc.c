/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:29:29 by vroche            #+#    #+#             */
/*   Updated: 2014/11/13 17:53:29 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*alloc;
	char	*cac;

	if (size == 0)
		return (NULL);
	if (!(alloc = (void *)malloc(size)))
		return (NULL);
	cac = (char *)alloc;
	while (size)
	{
		*cac++ = 0;
		size--;
	}
	return (alloc);
}
