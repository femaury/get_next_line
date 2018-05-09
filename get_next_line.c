/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:02:11 by femaury           #+#    #+#             */
/*   Updated: 2018/05/09 13:35:01 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static int	ft_readline(const int fd, t_list *curr)
{
	char	buff[BUFF_SIZE + 1];
	int		rd;

	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		curr->content = ft_strjoin(curr->content, buff);
		ft_memdel(&curr->content_ptr);
		curr->content_ptr = curr->content;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (rd);
}

static int	ft_copyline(t_list *curr, char **line)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (*(char *)(curr->content))
	{
		while (*(char *)(curr->content + i) != '\n' && *(char *)(curr->content + i))
			i++;
//		if (line)
//			ft_strdel(line);
		if (!(*line = (char *)ft_memalloc(i + 1)))
			return (-1);
		while (j < i)
		{
			*(*line + j) = *(char *)(curr->content + j);
			j++;
		}
		*(*line + i) = '\0';
		curr->content += (i + 1);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*curr;
	int				rd;

	if (fd < 0 || !line)
		return (-1);
	if (!(curr = ft_lstfind_size(files, fd)))
	{
		if (!(curr = ft_lstnew("\0", 1)))
			return (-1);
		curr->content_size = fd;
		ft_lstadd(&files, curr);
	}
	if ((rd = ft_readline(fd, curr)) < 0)
		return (rd);
	return (ft_copyline(curr, line));
}
/*
int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		fd2;

	if (ac == 3)
	{
//		line = ft_memalloc(1);
		fd = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			ft_putendl(line);
			ft_strdel(&line);
			while (get_next_line(fd2, &line) > 0)
			{
				ft_putendl(line);
				ft_strdel(&line);
			}
		}
		ft_strdel(&line);
		close(fd);
	}
	while (1)
	{
	}
	return (0);
}*/
