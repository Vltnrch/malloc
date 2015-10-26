/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 14:29:16 by vroche            #+#    #+#             */
/*   Updated: 2015/10/26 18:56:17 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block	*get_block_free(t_env *env, size_t size, char type, t_page **ptrp)
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
