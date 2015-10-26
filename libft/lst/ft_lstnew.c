/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:43:19 by vroche            #+#    #+#             */
/*   Updated: 2014/11/10 13:31:13 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*dest;

	if (!(dest = (void *)ft_memalloc(content_size + 1)))
		return (NULL);
	if (content == NULL)
	{
		dest = NULL;
		content_size = 0;
	}
	else
		dest = ft_memcpy(dest, content, content_size);
	if (!(list = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	list->content_size = content_size;
	list->next = NULL;
	list->content = dest;
	return (list);
}
