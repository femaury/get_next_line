/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:02:11 by femaury           #+#    #+#             */
/*   Updated: 2018/04/28 17:48:05 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

static int	ft_copyline(t_list *curr, char *line)
{
	unsigned int	i;

	i = 0;
	if (*(char *)(curr->content))
	{
		while (*(char *)(curr->content) != '\n' && *(char *)(curr->content))
			line[i++] = *(char *)(curr->content)++;
		line[i] = '\0';
		if (*(char *)(curr->content) == '\n')
			curr->content++;
		return (1);
	}
	else
		return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*curr;
	char			buff[BUFF_SIZE + 1];
	int				rd;

	if (fd < 0 || !line)
		return (-1);
	if (!(curr = ft_lstfind_size(files, fd)))
	{
		if ((rd = read(fd, buff, BUFF_SIZE)) <= 0)
			return (rd) ? (-1) : (0);
		buff[rd] = '\0';
		if (!(curr = ft_lstnew(buff, rd + 1)))
			return (-1);
		curr->content_size = fd;
		ft_lstadd(&files, curr);
	}
	else if (*line)
		ft_strdel(line);
	if (!(*line = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	return (ft_copyline(curr, *line));
}
