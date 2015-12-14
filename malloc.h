/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 14:29:16 by vroche            #+#    #+#             */
/*   Updated: 2015/11/27 15:59:46 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/resource.h>
# include <sys/mman.h>
# include <pthread.h>

# define INIT (4 * getpagesize())
# define TINY (4 * env->getpagesize)
# define MAXTINY (128)
# define SMALL (26 * env->getpagesize)
# define MAXSMALL (1024)

# define TINYPAGE 1
# define SMALLPAGE 2
# define LARGEPAGE 3

# define NBLENGHT (new->ptr + new->size + sizeof(t_block))

typedef struct		s_block
{
	size_t			size;
	char			isfree;
	void			*ptr;
	struct s_block	*prev;
	struct s_block	*next;
}					t_block;

typedef struct		s_page
{
	char			type;
	size_t			size;
	void			*end;
	struct s_block	*block;
	struct s_page	*prev;
	struct s_page	*next;
}					t_page;

typedef struct		s_env
{
	struct s_page	*pages;
	int				getpagesize;
	struct rlimit	rlp;
}					t_env;

t_env				*get_env_malloc(void);
pthread_mutex_t		*get_mutex_malloc(void);
int					find_block(t_env *env, t_page **ptrp, \
								t_block **ptrb, void *ptr);
void				prepare_intermediate_block(t_block *new);

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);

void				show_alloc_mem(void);

#endif
