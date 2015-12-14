/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 14:28:55 by vroche            #+#    #+#             */
/*   Updated: 2015/12/12 22:37:21 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_block	*add_page(t_env *env, size_t size, char type, t_page **ptrp)
{
	void	*ptr;
	t_page	*page;

	if ((ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,\
				-1, 0)) == MAP_FAILED)
		return (NULL);
	page = env->pages;
	while (page->next)
		page = page->next;
	page->next = (t_page *)ptr;
	page->next->prev = page;
	page = page->next;
	page->type = type;
	page->size = size - sizeof(t_page);
	page->block = (t_block *)(ptr + sizeof(t_page));
	page->end = ptr + size - 1;
	page->next = NULL;
	page->block->size = page->size - sizeof(t_block);
	page->block->isfree = 1;
	page->block->ptr = ptr + sizeof(t_page) + sizeof(t_block);
	page->block->prev = NULL;
	page->block->next = NULL;
	*ptrp = page;
	return (page->block);
}

static void		*prepare_new_block(t_page *page, t_block *new, size_t size)
{
	void	*ptr;

	if (!new)
	{
		pthread_mutex_unlock(get_mutex_malloc());
		return (NULL);
	}
	ptr = new->ptr;
	new->size = size;
	new->isfree = 0;
	if ((new->next == NULL && NBLENGHT < page->end))
	{
		new->next = new->ptr + new->size;
		new->next->prev = new;
		new = new->next;
		new->size = page->end - (void *)new - sizeof(t_block) + 1;
		new->isfree = 1;
		new->ptr = (void *)new + sizeof(t_block);
		new->next = NULL;
	}
	else if ((new->next && NBLENGHT < (void *)new->next))
		prepare_intermediate_block(new);
	pthread_mutex_unlock(get_mutex_malloc());
	return (ptr);
}

static t_block	*get_block_free(t_env *env, size_t size, \
								char type, t_page **ptrp)
{
	t_page	*page;
	t_block	*block;

	page = env->pages;
	while (page)
	{
		if (page->type == type)
		{
			block = page->block;
			while (block)
			{
				if (block->isfree && size <= block->size)
				{
					*ptrp = page;
					return (block);
				}
				block = block->next;
			}
		}
		page = page->next;
	}
	*ptrp = NULL;
	return (NULL);
}

void			*malloc(size_t size)
{
	t_block		*block;
	t_env		*env;
	t_page		*page;

	if (!(env = get_env_malloc()) || size >= env->rlp.rlim_cur)
		return (NULL);
	pthread_mutex_lock(get_mutex_malloc());
	block = NULL;
	size = (size == 0) ? 1 : size;
	if (size <= MAXTINY)
		block = get_block_free(env, size, TINYPAGE, &page);
	else if (size <= MAXSMALL)
		block = get_block_free(env, size, SMALLPAGE, &page);
	if (!block)
	{
		if (size <= MAXTINY)
			block = add_page(env, TINY, TINYPAGE, &page);
		else if (size <= MAXSMALL)
			block = add_page(env, SMALL, SMALLPAGE, &page);
		else
			block = add_page(env, ((size + sizeof(t_page) + sizeof(t_block)) \
			/ env->getpagesize + 1) * env->getpagesize, LARGEPAGE, &page);
	}
	return (prepare_new_block(page, block, size));
}
