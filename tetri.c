/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 07:51:25 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/03 03:11:02 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_tetri(t_tetri *tetri)
{
	int count;

	count = 0;
	while (tetri)
	{
		tetri = tetri->next;
		count++;
	}
	return (count);
}

t_tetri		*new_tetri(t_id_piece id)
{
	t_tetri *tetri;

	tetri = ft_malloc(sizeof(t_tetri));
	tetri->id = id;
	tetri->lettre = 0;
	tetri->next = 0;
	tetri->position.x = 0;
	tetri->position.y = 0;
	return (tetri);
}

t_tetri		*add_tetri(t_tetri *previous, t_id_piece id)
{
	t_tetri *tetri;

	tetri = ft_malloc(sizeof(t_tetri));
	tetri->id = id;
	previous->next = tetri;
	tetri->lettre = previous->lettre + 1;
	tetri->next = 0;
	tetri->position.x = 0;
	tetri->position.y = 0;
	return (tetri);
}

void		open_lst_tetri(t_app *app)
{
	int				fd;
	int				rt;
	unsigned char	*data;
	t_tetri			*cursor;

	rt = 1;
	fd = ft_open(app->av[1], O_RDONLY);
	rt = readfile(fd, &data, rt);
	app->tetri = new_tetri(idfrompiece(lire_piece(data), app->pieces));
	ft_free(data);
	cursor = app->tetri;
	rt = readfile(fd, &data, rt);
	while (rt != 0)
	{
		cursor = add_tetri(cursor, idfrompiece(lire_piece(data), app->pieces));
		ft_free(data);
		rt = readfile(fd, &data, rt);
	}
	close(fd);
	app->nb_tetri = count_tetri(app->tetri);
	if (app->nb_tetri > 26)
		ft_puterror();
	app->nb_point = app->nb_tetri * 4;
}

void		free_tetri(t_tetri **tetri)
{
	t_tetri *cursor;
	t_tetri *cursor2;

	cursor2 = *tetri;
	while (cursor2)
	{
		cursor = cursor2->next;
		ft_free(cursor2);
		cursor2 = 0;
		cursor2 = cursor;
	}
}
