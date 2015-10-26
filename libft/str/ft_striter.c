/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:41:33 by vroche            #+#    #+#             */
/*   Updated: 2014/11/10 15:25:49 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	len;

	if (s == NULL || f == NULL)
		return ;
	len = ft_strlen(s);
	while (len)
	{
		(*f)(s++);
		len--;
	}
}
