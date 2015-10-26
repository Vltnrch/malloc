/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 12:54:11 by vroche            #+#    #+#             */
/*   Updated: 2015/10/18 14:52:50 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>

# define BUFF_PF 127
# define R_PF 0
# define HH_PF 1
# define H_PF 2
# define L_PF 3
# define LL_PF 4
# define J_PF 5
# define Z_PF 6

typedef struct		s_optp
{
	int				d;
	int				z;
	int				l;
	int				m;
	int				s;
	int				bd;
	int				ad;
}					t_optp;

typedef struct		s_pf
{
	const char		*format;
	char			*str;
	char			*tmp;
	int				cnt;
	int				rcnt;
	int				fd;
	struct s_optp	*optp;
}					t_pf;

int					ft_pbuff(t_pf *pf);
void				ft_strncpypf(t_pf *pf, char *src, size_t n);
void				ft_strcharpf(t_pf *pf, char c, size_t n);
void				ft_clear_pbuff(t_pf **pf);

void				ft_perc(t_pf *pf, va_list ap);

void				ft_percs(t_pf *pf, va_list ap, int height);
void				ft_percc(t_pf *pf, va_list ap, int height);

void				ft_percdi(t_pf *pf, va_list ap, int height);
void				ft_percoux(t_pf *pf, va_list ap, int height, char c);
void				ft_percp(t_pf *pf, va_list ap);

int					ft_perch(t_pf *pf);

void				ft_percopt_init(t_optp *optp);
void				ft_percpre(t_pf *pf, t_optp *optp, va_list ap);
void				ft_percopt(t_pf *pf, t_optp *optp, va_list ap);

int					ft_dprintf(int fd, const char *format, ...);
int					ft_printf(const char *format, ...);
int					ft_vdprintf(int fd, const char *format, va_list ap);
int					ft_vprintf(const char *format, va_list ap);

void				ft_put_di(t_pf *pf, char *s);

void				ft_put_ou(t_pf *pf, char *s);

void				ft_put_x(t_pf *pf, char *s, char c);

void				ft_put_p(t_pf *pf, char *s);

void				ft_put_s(t_pf *pf, char *s);
void				ft_put_c(t_pf *pf, char c);

void				ft_put_ss(t_pf *pf, wchar_t *s);

int					ft_witoa(char *dest, wint_t src);
int					*ft_wctoa(char **dest, wchar_t *src);

#endif
