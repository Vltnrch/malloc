/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:16:10 by vroche            #+#    #+#             */
/*   Updated: 2014/11/12 16:06:24 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t oldsize, size_t size)
{
	void	*str;

	if (ptr == NULL)
		return (NULL);
	if (size == 0)
	{
		if (!(str = ft_memalloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (str);
	}
	if (!(str = ft_memalloc(size)))
		return (NULL);
	ft_memcpy(str, ptr, (oldsize >= size) ? size : oldsize);
	ft_memdel(&ptr);
	return (str);
}
