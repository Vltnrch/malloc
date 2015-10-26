/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 15:54:30 by vroche            #+#    #+#             */
/*   Updated: 2015/10/26 19:17:20 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_env	*prepare_env(void)
{
	t_env	*env;
	void	*ptr;
	t_page	*page;
	t_block	*block;

	if (!(ptr = mmap(0, INIT, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		ft_putstr_fd("mmap failed\n", 2);
	env = (t_env *)ptr;
	env->pages = (t_page *)(ptr + sizeof(t_env));
	env->getpagesize = getpagesize();
	if (getrlimit(RLIMIT_AS, &(env->rlp)) == -1)
		ft_putstr_fd("getrlimit failed\n", 2);
	env->totalsize = TINY;
	page = env->pages;
	page->type = TINYPAGE;
	page->size = TINY - sizeof(t_env) - sizeof(t_page);
	block = (t_block *)(ptr + sizeof(t_env) + sizeof(t_page));
	page->block = block;
	page->next = NULL;
	page->end = ptr + TINY - 1;
	block->size = page->size - sizeof(t_block);
	block->isfree = 1;
	block->ptr = ptr + sizeof(t_env) + sizeof(t_page) + sizeof(t_block);
	block->next = NULL;
	return (env);
}

t_env	*get_env(void)
{
	static t_env	*env = NULL;

	if (!env)
		env = prepare_env();
	return (env);
}
