/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 15:54:30 by vroche            #+#    #+#             */
/*   Updated: 2015/11/25 17:44:08 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_env	*prepare_env(void)
{
	t_env	*env;
	void	*ptr;

	if ((ptr = mmap(0, INIT, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, \
				-1, 0)) == MAP_FAILED)
		return (NULL);
	env = (t_env *)ptr;
	env->pages = (t_page *)(ptr + sizeof(t_env));
	env->getpagesize = getpagesize();
	if (getrlimit(RLIMIT_AS, &(env->rlp)) == -1)
		write(2, "getrlimit failed\n", sizeof("getrlimit failed\n"));
	env->totalsize = TINY;
	env->pages->type = TINYPAGE;
	env->pages->size = TINY - sizeof(t_env) - sizeof(t_page);
	env->pages->block = (t_block *)(ptr + sizeof(t_env) + sizeof(t_page));
	env->pages->prev = NULL;
	env->pages->next = NULL;
	env->pages->end = ptr + TINY - 1;
	env->pages->block->size = env->pages->size - sizeof(t_block);
	env->pages->block->isfree = 1;
	env->pages->block->ptr = ptr + sizeof(t_env) + sizeof(t_page) + \
						sizeof(t_block);
	env->pages->block->prev = NULL;
	env->pages->block->next = NULL;
	return (env);
}

t_env			*get_env_malloc(void)
{
	static t_env	*env = NULL;

	if (!env)
		env = prepare_env();
	return (env);
}

pthread_mutex_t	*get_mutex_malloc(void)
{
	static	pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

	return (&mutex);
}

int				find_block(t_env *env, t_page **ptrp, t_block **ptrb, void *ptr)
{
	t_page	*page;
	t_block	*block;

	page = env->pages;
	while (page)
	{
		if (ptr > (void *)page && ptr < page->end)
		{
			block = page->block;
			while (block)
			{
				if (block->ptr == ptr)
				{
					*ptrb = block;
					*ptrp = page;
					return (1);
				}
				block = block->next;
			}
		}
		if (ptr > (void *)page && ptr < page->end)
			return (0);
		page = page->next;
	}
	return (0);
}
