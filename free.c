/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 15:13:25 by vroche            #+#    #+#             */
/*   Updated: 2015/11/23 15:23:44 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	ft_free_defrag(t_block *block)
{
	if (block->prev && block->prev->isfree)
	{
		block->prev->size += block->size + sizeof(t_block);
		block->prev->next = block->next;
		if (block->next)
			block->next->prev = block->prev;
		block = block->prev;
	}
	if (block->next && block->next->isfree)
	{
		block->size += block->next->size + sizeof(t_block);
		if (block->next->next)
			block->next->next->prev = block;
		block->next = block->next->next;
	}
}

static void	ft_munmap(t_page *page)
{
	if (page->prev)
		page->prev->next = page->next;
	if (page->next)
		page->next->prev = page->prev;
	if (munmap((void *)page, page->size + sizeof(t_page)) == -1)
		write(2, "free : munmmap failed\n", sizeof("munmmap failed\n"));
}

static void	ft_free_check_unmap_part(t_env *env, t_page *page)
{
	int		i;
	t_page	*pages;

	pages = env->pages;
	i = 0;
	while (pages)
	{
		if (pages->type == page->type && pages != page)
		{
			i++;
			break ;
		}
		pages = pages->next;
	}
	if (i)
		ft_munmap(page);
}

static void	ft_free_check_unmap(t_env *env, t_page *page)
{
	t_block	*block;
	int		i[2];

	if ((page->type == TINYPAGE || page->type == SMALLPAGE) \
		&& env->pages != page)
	{
		block = page->block;
		i[0] = 0;
		i[1] = 0;
		while (block)
		{
			if (block->isfree)
				i[0]++;
			else
				i[1]++;
			block = block->next;
		}
		if (i[1] > 0 || i[0] > 1)
			return ;
		ft_free_check_unmap_part(env, page);
	}
	else if (page->type == LARGEPAGE)
		ft_munmap(page);
}

void		free(void *ptr)
{
	t_block		*block;
	t_env		*env;
	t_page		*page;

	if (!ptr || !(env = get_env_malloc()))
		return ;
	page = env->pages;
	if (!find_block(env, &page, &block, ptr))
		return ;
	pthread_mutex_lock(get_mutex_malloc());
	block->isfree = 1;
	ft_free_defrag(block);
	ft_free_check_unmap(env, page);
	pthread_mutex_unlock(get_mutex_malloc());
}
