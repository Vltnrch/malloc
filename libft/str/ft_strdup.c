/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/07 19:16:54 by vroche            #+#    #+#             */
/*   Updated: 2014/11/06 13:05:49 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s;

	i = ft_strlen(s1) + 1;
	if (!(s = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	s = ft_strcpy(s, s1);
	return (s);
}
