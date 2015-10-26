/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:12:10 by vroche            #+#    #+#             */
/*   Updated: 2014/11/10 15:27:38 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t			len;
	unsigned int	i;
	char			*dest;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(dest = ft_strnew(len)))
		return (NULL);
	while (len)
	{
		*dest++ = (*f)(*s++);
		len--;
		i++;
	}
	return (dest - i);
}
