/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:29:13 by femaury           #+#    #+#             */
/*   Updated: 2018/04/17 16:47:05 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned int	i;
	char			*str;

	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
