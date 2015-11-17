/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 15:19:50 by vroche            #+#    #+#             */
/*   Updated: 2015/11/17 19:16:11 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

#include <stdio.h>

void show_alloc_mem(void)
{
	t_env	*env;
	t_page	*page;
	t_block	*block;
	size_t	total;

	if (!(env = get_env_malloc()))
		return ;
	page = env->pages;
	total = 0;
	while (page)
	{
		if (page->type == TINYPAGE)
			printf("%s - %p\n", "TINY", (void *)page);
		else if (page->type == SMALLPAGE)
			printf("%s - %p\n", "SMALL", (void *)page);
		else
			printf("%s - %p\n", "LARGE", (void *)page);
		block = page->block;
		while (block)
		{
			if (!block->isfree)
			{
				printf("%p - %p : %zu octets\n", block->ptr, block->ptr + block->size, block->size);
				total += block->size;
			}
			block = block->next;
		}
		page = page->next;
	}
	printf("Total : %zu octets\n", total);
}