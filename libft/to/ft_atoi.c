/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:56:32 by vroche            #+#    #+#             */
/*   Updated: 2015/01/22 16:04:19 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int	signe;
	int	dest;
	int	check;

	signe = 1;
	dest = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n') || \
			(*str == '\v') || (*str == '\r') || (*str == '\f'))
		str++;
	if (ft_strcmp("-2147483648", str) == 0)
		return (-2147483648);
	if ((*str == '-') || (*str == '+'))
		if (*str++ == '-')
			signe = -1;
	while (*str >= '0' && *str <= '9')
	{
		check = dest;
		dest *= 10;
		dest += ((int)*str - '0');
		if (check > dest)
			return (-1);
		str++;
	}
	return (dest * signe);
}
