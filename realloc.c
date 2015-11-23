/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 12:56:02 by vroche            #+#    #+#             */
/*   Updated: 2015/11/23 15:26:20 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	while (n)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}

void		*realloc(void *ptr, size_t size)
{
	t_block		*block;
	t_env		*env;
	t_page		*page;
	void		*new;

	if (!ptr || !(env = get_env_malloc()))
		return (NULL);
	if (!find_block(env, &page, &block, ptr))
		return (NULL);
	if (!(new = malloc(size)))
		return (NULL);
	ft_memcpy(new, ptr, block->size > size ? size : block->size);
	free(ptr);
	return (new);
}
