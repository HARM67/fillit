/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 07:51:20 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/03 02:17:47 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		verif_piece(unsigned char *str)
{
	int		temoin;
	char	i;
	char	diese;
	char	point;

	i = -1;
	diese = 0;
	point = 0;
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' ||
			str[19] != '\n' || str[20] != '\n')
		temoin = 1;
	while (++i < 21)
		if (str[(int)i] == '.')
			point++;
		else if (str[(int)i] == '#')
			diese++;
	if (point != 12 || diese != 4 || temoin == 1)
		ft_puterror();
}

t_piece		lire_piece(unsigned char *str)
{
	int			i;
	int			j;
	t_piece		piece;
	t_vecteur	v;

	i = 0;
	j = 0;
	verif_piece(str);
	v.x = 10;
	v.y = 10;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			piece.obs[j].x = i % 5;
			piece.obs[j].y = i / 5;
			v.x = (v.x < piece.obs[j].x) ? v.x : piece.obs[j].x;
			v.y = (v.y < piece.obs[j].y) ? v.y : piece.obs[j].y;
			j++;
		}
		i++;
	}
	piece = translate_piece(piece, invert_vecteur(v));
	return (piece);
}

void		init_piece(t_app *app)
{
	long int *p;

	p = (long int *)ft_malloc(sizeof(t_piece) * 19);
	p[0] = 844433520132096;
	p[1] = 216174981153816576;
	p[2] = 144116287587549184;
	p[3] = 144116291899228161;
	p[4] = 144398862092664833;
	p[5] = 72620552581349376;
	p[6] = 72621647798009856;
	p[7] = 72621647814721536;
	p[8] = 144397766859227136;
	p[9] = 144397766875938816;
	p[10] = 144398862092599296;
	p[11] = 72621647814721538;
	p[12] = 72340168526397441;
	p[13] = 72057602627928064;
	p[14] = 144116291899228160;
	p[15] = 72339077604638720;
	p[16] = 144397766875938817;
	p[17] = 72621647814721537;
	p[18] = 72340168526331904;
	app->pieces = (t_piece*)p;
}
