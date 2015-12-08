/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:53:51 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/03 02:21:24 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_app(t_app **app, int ac, char **av)
{
	*app = (t_app*)ft_malloc(sizeof(t_app));
	(*app)->ac = ac;
	(*app)->av = av;
	(*app)->grille = (t_grille*)ft_malloc(sizeof(t_grille));
	init_piece(*app);
	open_lst_tetri(*app);
	(*app)->nb_point = (*app)->nb_tetri * 4;
	(*app)->nb_tetri = count_tetri((*app)->tetri);
}

void	run_app(t_app *app)
{
	resolution(app);
}

void	free_app(t_app **app)
{
	free_tetri(&(*app)->tetri);
	ft_free((*app)->pieces);
	ft_free(*(app));
	app = 0;
}
