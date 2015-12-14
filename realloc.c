/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 12:56:02 by vroche            #+#    #+#             */
/*   Updated: 2015/12/12 22:38:36 by vroche           ###   ########.fr       */
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

static void	*realloc_malloc(void *ptr, size_t size, t_block *block)
{
	void		*new;

	if (!(new = malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new, ptr, block->size > size ? size : block->size);
		free(ptr);
	}
	return (new);
}

void		*realloc(void *ptr, size_t size)
{
	t_block		*block;
	t_env		*env;
	t_page		*page;

	if (!(env = get_env_malloc()))
		return (NULL);
	pthread_mutex_lock(get_mutex_malloc());
	if (ptr && !find_block(env, &page, &block, ptr))
	{
		pthread_mutex_unlock(get_mutex_malloc());
		return (NULL);
	}
	if (ptr && block->size > size)
	{
		block->size = size;
		if ((block->next && block->ptr + block->size + sizeof(t_block) \
						< (void *)block->next))
			prepare_intermediate_block(block);
		pthread_mutex_unlock(get_mutex_malloc());
		return (ptr);
	}
	pthread_mutex_unlock(get_mutex_malloc());
	return (realloc_malloc(ptr, size, block));
}
