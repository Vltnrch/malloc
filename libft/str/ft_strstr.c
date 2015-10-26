/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 17:55:24 by vroche            #+#    #+#             */
/*   Updated: 2014/11/09 18:49:50 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s2);
	i = 0;
	if (len == 0)
		return ((char*)s1);
	else if (ft_strlen(s1) < len)
		return (NULL);
	while (s1[i + len - 1] != '\0')
	{
		if (ft_memcmp(s1 + i, s2, len) == 0)
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
