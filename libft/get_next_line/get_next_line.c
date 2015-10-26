/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:38:54 by vroche            #+#    #+#             */
/*   Updated: 2014/12/08 15:52:05 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_end_line(char *line, t_list *save, size_t lenl)
{
	while (lenl)
	{
		if (*line == '\n')
		{
			*line++ = '\0';
			ft_strncpy(save->content, line, lenl);
			ft_strclr(line);
			return (1);
		}
		line++;
		lenl--;
	}
	return (0);
}

static int	ft_readline(int const fd, char **line, t_list *save)
{
	int				pos;
	unsigned int	len;
	char			*temp;

	if (check_end_line(*line, save, (len = ft_strlen(*line))) == 1)
		return (1);
	temp = *line;
	*line += len;
	while ((pos = read(fd, *line, BUFF_SIZE)) > 0)
	{
		len = len + pos;
		if (check_end_line(*line, save, pos) == 1)
		{
			*line = temp;
			return (1);
		}
		if (!(*line = ft_realloc(temp, len, len + BUFF_SIZE + 1)))
			return (-1);
		temp = *line;
		*line += len;
	}
	*line = temp;
	if (ft_strlen(*line) != 0 && pos == 0)
		return (1);
	return (pos);
}

static int	check_already_fd(int const fd, char **line, t_list *save)
{
	char	*nn;
	t_list	*new;

	while (save->next != NULL && save->content_size != (size_t)fd)
		save = save->next;
	if (save->content_size == (size_t)fd)
	{
		if (!(*line = ft_strnew(ft_strlen(save->content) + BUFF_SIZE)))
			return (-1);
		*line = ft_strncpy(*line, save->content, ft_strlen(save->content));
		ft_strclr(save->content);
		return (ft_readline(fd, line, save));
	}
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!(nn = (char *)ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!(new = ft_lstnew(nn, BUFF_SIZE + 1)))
		return (-1);
	ft_memdel((void **)&nn);
	new->content_size = (size_t)fd;
	save->next = new;
	return (ft_readline(fd, line, new));
}

static void	delete_fd(int const fd, t_list **save)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*save)->content_size == (size_t)fd)
	{
		tmp = *save;
		*save = (*save)->next;
		free(tmp->content);
		free(tmp);
		return ;
	}
	tmp = *save;
	tmp2 = tmp->next;
	while (tmp2 != NULL && tmp2->content_size != (size_t)fd)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	if (tmp2 != NULL)
	{
		tmp->next = tmp2->next;
		free(tmp2->content);
		free(tmp2);
	}
}

int			get_next_line(int const fd, char **line)
{
	static t_list	*save;
	char			*nn;
	int				pos;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	if (save == NULL)
	{
		if (!(nn = (char *)ft_strnew(BUFF_SIZE)))
			return (-1);
		if (!(save = ft_lstnew(nn, BUFF_SIZE + 1)))
			return (-1);
		ft_memdel((void *)&nn);
		save->content_size = (size_t)fd;
	}
	pos = check_already_fd(fd, line, save);
	if (pos == 0 || pos == -1)
		delete_fd(fd, &save);
	return (pos);
}
