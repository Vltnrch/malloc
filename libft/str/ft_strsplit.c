/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:17:28 by vroche            #+#    #+#             */
/*   Updated: 2014/11/10 16:55:37 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countstr(char const *s, char c)
{
	size_t		nb;

	nb = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			nb++;
			s++;
			while (*s != c && *s)
				s++;
		}
	}
	return (nb);
}

static char		*ft_addstr(size_t *i, char const *s, char c)
{
	size_t		size;
	size_t		j;
	char		*word;

	size = *i;
	j = 0;
	while (s[size] && s[size] != c)
		size++;
	if (!(word = ft_strnew(size - *i)))
		return (NULL);
	while (*i < size)
	{
		word[j] = s[*i];
		j++;
		*i += 1;
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**dst;
	size_t		o;
	size_t		*i;
	size_t		j;

	if (s == NULL)
		return (NULL);
	o = 0;
	i = &o;
	j = 0;
	if (!(dst = (char **)malloc(sizeof(char *) * (ft_countstr(s, c) + 1))))
		return (NULL);
	while (j < ft_countstr(s, c))
	{
		while (s[*i] == c)
			*i += 1;
		if (s[*i] != c && s[*i])
			dst[j++] = ft_addstr(i, s, c);
	}
	dst[j] = 0;
	return (dst);
}
