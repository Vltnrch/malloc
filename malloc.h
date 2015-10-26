/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 14:29:16 by vroche            #+#    #+#             */
/*   Updated: 2015/10/26 16:37:33 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <sys/resource.h>
# include <sys/mman.h>

# define INIT (4 * getpagesize())
# define TINY (4 * env->getpagesize)
# define MAXTINY (128)
# define SMALL (26 * env->getpagesize)
# define MAXSMALL (1024)

# define TINYPAGE 1
# define SMALLPAGE 2
# define LARGEPAGE 3
/*     int
     getrlimit(RLIMIT_AS, struct rlimit *rlp);*/

 /*   int
    getpagesize(void);*/

typedef struct		s_block
{
	size_t			size;
	char			isfree;
	void			*ptr;
	struct s_block	*next;
}					t_block;

typedef struct		s_page
{
	char			type;
	size_t			size;
	void			*end;
	struct s_block	*block;
	struct s_page	*next;
}					t_page;

typedef struct		s_env
{
	struct s_page	*pages;
	int				getpagesize;
	struct rlimit	rlp;
	rlim_t			totalsize;
}					t_env;

t_env				*get_env(void);

t_block				*get_block_free(t_env *env, size_t size, char type, t_page **page);

#endif