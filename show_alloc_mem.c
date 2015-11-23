/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 15:19:50 by vroche            #+#    #+#             */
/*   Updated: 2015/11/23 15:26:25 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static int	size_base(size_t n, int base)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		size++;
		n /= base;
	}
	return (size);
}

static void	ft_printaddr(void *n)
{
	char		ptr[19];
	size_t		d;
	int			size;
	int			m;

	d = (size_t)n;
	size = size_base(d, 16);
	ptr[0] = '0';
	ptr[1] = 'x';
	while (d > 0)
	{
		m = d % 16;
		if (m > 9)
			ptr[size + 1] = ('7' + m);
		else
			ptr[size + 1] = ('0' + m);
		d /= 16;
		size--;
	}
	size = size_base((size_t)n, 16);
	write(1, ptr, size + 2);
}

static void	ft_printsizet(size_t n)
{
	char		ptr[32];
	int			size;
	int			m;
	size_t		d;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	d = n;
	size = size_base(n, 10);
	while (n > 0)
	{
		m = n % 10;
		ptr[size - 1] = ('0' + m);
		n /= 10;
		size--;
	}
	size = size_base(d, 10);
	write(1, ptr, size);
}

static void	print_page_block(t_page *page, t_block *block, size_t *total)
{
	if (page != NULL)
	{
		if (page->type == TINYPAGE)
			write(1, "TINY : ", 7);
		else if (page->type == SMALLPAGE)
			write(1, "SMALL : ", 8);
		else
			write(1, "LARGE : ", 8);
		ft_printaddr((void *)page);
		write(1, "\n", 1);
		return ;
	}
	if (block != NULL)
	{
		ft_printaddr(block->ptr);
		write(1, " - ", 3);
		ft_printaddr(block->ptr + block->size);
		*total += block->size;
	}
	else
		write(1, "Total", 5);
	write(1, " : ", 3);
	ft_printsizet(block == NULL ? *total : block->size);
	write(1, " octets\n", 8);
}

void		show_alloc_mem(void)
{
	t_env	*env;
	t_page	*page;
	t_block	*block;
	size_t	total;

	if (!(env = get_env_malloc()))
		return ;
	page = env->pages;
	total = 0;
	pthread_mutex_lock(get_mutex_malloc());
	while (page)
	{
		print_page_block(page, NULL, &total);
		block = page->block;
		while (block)
		{
			if (!block->isfree)
				print_page_block(NULL, block, &total);
			block = block->next;
		}
		page = page->next;
	}
	print_page_block(NULL, NULL, &total);
	pthread_mutex_unlock(get_mutex_malloc());
}
