/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 04:33:31 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/03 02:38:25 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_grille(t_app *app)
{
	int			i;
	char		**p_map;

	p_map = app->grille->map;
	i = 0;
	while (i < app->grille->size)
	{
		ft_free(p_map[i]);
		i++;
	}
	ft_free(p_map);
	p_map = 0;
}

void	init_grille(t_app *app)
{
	unsigned char	t;
	char			**map;

	t = 0;
	app->grille->map = (char**)ft_malloc(sizeof(char*) * app->grille->size);
	map = app->grille->map;
	while (t < app->grille->size)
	{
		map[t] = (char*)ft_malloc(sizeof(char) * app->grille->size);
		ft_memset(map[t], '.', app->grille->size);
		map[t][app->grille->size] = '\0';
		t++;
	}
}

void	remove_tetri(t_app *app, t_tetri *tetri)
{
	unsigned char	i;
	t_piece			piece_posee;

	i = 0;
	piece_posee = translate_piece(app->pieces[tetri->id], tetri->position);
	while (i < 4)
	{
		app->grille->map[piece_posee.obs[i].y][piece_posee.obs[i].x] = '.';
		i++;
	}
}

void	insert_tetri(t_app *app, t_tetri *tetri)
{
	unsigned char	i;
	t_piece			piece_p;
	char			**map;

	i = 0;
	map = app->grille->map;
	piece_p = translate_piece(app->pieces[tetri->id], tetri->position);
	while (i < 4)
	{
		map[piece_p.obs[i].y][piece_p.obs[i].x] = tetri->lettre + 'A';
		i++;
	}
}

void	print_grille(t_app *app)
{
	int i;

	i = 0;
	while (i < app->grille->size)
	{
		ft_putendl((char*)app->grille->map[i]);
		i++;
	}
}
