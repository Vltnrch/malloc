/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 14:28:55 by vroche            #+#    #+#             */
/*   Updated: 2015/10/26 19:16:59 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block	*add_page(t_env *env, size_t size, char type, t_page **ptrp)
{
	void	*ptr;
	t_page	*page;
	t_block	*block;

	if (!(ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
			ft_putstr_fd("mmap failed\n", 2);
	page = env->pages;
	while (page->next)
		page = page->next;
	page->next = (t_page *)ptr;
	page = page->next;
	page->type = type;
	page->size = TINY - sizeof(t_page);
	block = (t_block *)(ptr + sizeof(t_page));
	page->block = block;
	page->end = ptr + size - 1;
	page->next = NULL;
	block->size = page->size - sizeof(t_block);
	block->isfree = 1;
	block->ptr = ptr + sizeof(t_page) + sizeof(t_block);
	block->next = NULL;
	*ptrp = page;
	return (block);
}

void	prepare_new_block(t_page *page, t_block *new)
{
	if (new->ptr + new->size + sizeof(t_block) < page->end)
	{
		new->next = new->ptr + new->size;
		new = new->next;
		new->size = page->end - (void *)new - sizeof(t_block) + 1;
		new->isfree = 1;
		new->ptr = (void *)new + sizeof(t_block);
		new->next = NULL;
	}
}

void	*ft_malloc(size_t size)
{
	t_block		*block;
	t_env		*env;
	t_page		*page;

	if (!(env = get_env()))
		return (NULL);
	block = NULL;
	if (!size || size >= env->rlp.rlim_cur)
		return (NULL);
	else if (size <= MAXTINY)
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
			block = add_page(env, ((((size + sizeof(t_page)) / env->getpagesize) + 1) * env->getpagesize) , LARGEPAGE, &page);
	}
	block->size = size;
	block->isfree = 0;
	block->next = NULL;
	prepare_new_block(page, block);
	return (block->ptr);
}

void	display()
{
	t_env	*env;
	t_page	*page;
	t_block	*block;


	env = get_env();
	page = env->pages;
	while (page)
	{
		printf("Page Type : %d / Start : %p / End : %p \n", (int)page->type, (void *)page, page->end);
		block = page->block;
		while (block)
		{
			printf("		Block : %p / FREE : %d / size : %zu / ptr : %p\n", (void *)block, (int)block->isfree, block->size, block->ptr);
			block = block->next;
		}
		page = page->next;
	}
}


int		main(void)
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024000)
	{
		addr = (char *)ft_malloc(1024);
		addr[0] = 42;
		i++;
	}
	/*display();
	printf("sizeof t_env %zu / sizeof t_page %zu / sizeof t_block %zu\n", sizeof(t_env), sizeof(t_page), sizeof(t_block));*/
	return (0);
}
