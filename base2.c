/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 22:51:15 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/03 02:21:52 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_puterror(void)
{
	ft_putendl("error");
	exit(1);
}

size_t	ft_read(int fd, void *buf, size_t size)
{
	int n;

	n = read(fd, buf, size);
	if (n == -1)
		ft_puterror();
	return (n);
}
