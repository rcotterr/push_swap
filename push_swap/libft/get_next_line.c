/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:50:51 by rcotter-          #+#    #+#             */
/*   Updated: 2019/03/15 20:45:49 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static void			ft_change_content(t_list *tmp, char **line)
{
	size_t			i;
	size_t			j;
	char			*old;

	i = 0;
	j = 0;
	old = tmp->content;
	while (((char *)tmp->content)[i] != '\n')
		i++;
	if (!(*line = ft_strsub(tmp->content, j, i)))
		return ;
	i++;
	if (!(tmp->content = ft_strsub(tmp->content, i,
	ft_strlen(tmp->content) - i)))
		return ;
	free(old);
	old = NULL;
}

static int			ft_almostend(char **line, t_list *tmp)
{
	if (!(*line = ft_strdup(tmp->content)))
		return (-1);
	tmp->content = ft_strdup("");
	return (1);
}

static int			ft_mread(const int fd, char **line, char *buf, t_list *tmp)
{
	int				ret;
	char			*old;

	while (ft_strchr(tmp->content, '\n') == NULL &&
	(ret = read(fd, buf, BUFF_SIZE)))
	{
		old = tmp->content;
		if (!(tmp->content = ft_strjoin(old, buf)))
			return (-1);
		ft_bzero(buf, BUFF_SIZE + 1);
		free(old);
		old = NULL;
	}
	if (ret == 0)
	{
		if (tmp->content && ft_strcmp(tmp->content, "") == 0)
			return (0);
		if (ft_strchr(tmp->content, '\n') == NULL)
			return (ft_almostend(line, tmp));
	}
	ft_change_content(tmp, line);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*tmp;
	char			buf[BUFF_SIZE + 1];
	t_list			*first;

	if (fd < 0 || !line || read(fd, 0, 0) == -1)
		return (-1);
	tmp = list;
	while (tmp)
	{
		if ((size_t)fd == tmp->content_size)
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		tmp = list;
		first = ft_lstnew("", 1);
		first->content_size = fd;
		first->next = list;
		tmp = first;
		list = tmp;
	}
	ft_bzero(buf, BUFF_SIZE + 1);
	return (ft_mread(fd, line, buf, tmp));
}
