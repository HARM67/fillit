/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:22:17 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/03 02:18:31 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			minimum_size(t_app *app)
{
	int i;

	i = 2;
	while (i * i < app->nb_point)
		i++;
	return (i);
}

int			isdispo(t_app *app, t_tetri *tetri)
{
	t_piece	piece;
	char	i;

	i = 0;
	piece = translate_piece(app->pieces[tetri->id], tetri->position);
	while (i < 4)
	{
		if (piece.obs[(int)i].x >= app->grille->size ||
				piece.obs[(int)i].y >= app->grille->size)
			return (0);
		if (app->grille->map[piece.obs[(int)i].y][piece.obs[(int)i].x] != '.')
			return (0);
		i++;
	}
	return (1);
}

char		place_tetri(t_app *app, t_tetri *tetri)
{
	tetri->position.x = 0;
	tetri->position.y = 0;
	while (tetri->position.y < app->grille->size)
	{
		while (tetri->position.x < app->grille->size)
		{
			if (isdispo(app, tetri))
			{
				insert_tetri(app, tetri);
				if (tetri->next == 0)
					return (1);
				if (place_tetri(app, tetri->next))
					return (1);
				remove_tetri(app, tetri);
			}
			tetri->position.x++;
		}
		tetri->position.x = 0;
		tetri->position.y++;
	}
	tetri->position.x = 0;
	tetri->position.y = 0;
	return (0);
}

void		resolution(t_app *app)
{
	app->grille->size = minimum_size(app);
	init_grille(app);
	while (place_tetri(app, app->tetri) == 0)
	{
		free_grille(app);
		app->grille->size++;
		init_grille(app);
	}
	print_grille(app);
	free_grille(app);
}
