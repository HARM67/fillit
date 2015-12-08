/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 07:51:32 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/03 02:22:35 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_open(const char *path, int oflag)
{
	int fd;

	if (path == 0)
		fd = 0;
	else
		fd = open(path, oflag);
	if (fd == -1)
		ft_puterror();
	return (fd);
}

void	ft_free(void *p)
{
	free(p);
}

void	*ft_malloc(size_t size)
{
	void	*p;
	int		i;

	i = 0;
	p = 0;
	while (p == 0 && i < 4)
	{
		p = malloc(size);
		i++;
	}
	if (p == 0)
		ft_puterror();
	return (p);
}

void	*ft_memdup(void *mem, unsigned int n)
{
	unsigned int	i;
	unsigned char	*rt;
	unsigned char	*c_mem;

	rt = (unsigned char *)ft_malloc(n);
	c_mem = (unsigned char *)mem;
	i = 0;
	while (i < n)
	{
		rt[i] = c_mem[i];
		i++;
	}
	return (rt);
}

int		readfile(int fd, unsigned char **rt, int t)
{
	char			buffer[21];
	int				n;

	n = ft_read(fd, buffer, 21);
	if (n == 0 && t == 2)
		return (0);
	if (n != 21 && n != 20)
		ft_puterror();
	*rt = (unsigned char *)ft_memdup(buffer, n);
	if (n == 20)
	{
		(*rt)[20] = '\n';
		return (2);
	}
	return (1);
}
