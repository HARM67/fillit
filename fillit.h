/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 07:51:28 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/03 02:37:20 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef	unsigned char		t_id_piece;
typedef struct s_app		t_app;
typedef struct s_grille		t_grille;
typedef struct s_vecteur	t_vecteur;
typedef	struct s_piece		t_piece;
typedef struct s_tetri		t_tetri;

struct						s_app
{
	int						ac;
	char					**av;
	t_grille				*grille;
	t_piece					*pieces;
	t_tetri					*tetri;
	int						nb_tetri;
	int						nb_point;
};

struct						s_grille
{
	char					**map;
	int						size;
};

struct						s_vecteur
{
	unsigned char					x;
	unsigned char					y;
};

struct						s_piece
{
	t_vecteur				obs[4];
};

struct						s_tetri
{
	t_id_piece				id;
	unsigned char			lettre;
	t_vecteur				position;
	t_tetri					*next;
};

void						init_piece(t_app *app);
t_piece						lire_piece(unsigned char *str);

t_piece						translate_piece(t_piece p, t_vecteur v);
t_id_piece					idfrompiece(t_piece piece, t_piece *tab);

int							count_tetri(t_tetri *tetri);
void						open_lst_tetri(t_app *app);
t_tetri						*new_tetri(t_id_piece id);
t_tetri						*add_tetri(t_tetri *previous, t_id_piece id);
void						free_tetri(t_tetri **tetri);

t_vecteur					invert_vecteur(t_vecteur v);
t_vecteur					set_vecteur(char x, char y);
t_vecteur					add_vecteur(t_vecteur v1, t_vecteur v2);

int							ft_open(const char *path, int oflag);
void						ft_free(void *p);
void						*ft_malloc(size_t size);
void						*ft_memdup(void *mem, unsigned int n);
int							readfile(int fd, unsigned char **rt, int t);

void						remove_tetri(t_app *app, t_tetri *tetri);
void						insert_tetri(t_app *app, t_tetri *tetri);
void						free_grille(t_app *app);
void						init_grille(t_app *app);
void						print_grille(t_app *app);

int							minimum_size(t_app *app);
void						resolution(t_app *app);

void						init_app(t_app **app, int argc, char **argv);
void						free_app(t_app **app);
void						run_app(t_app *app);

size_t						ft_read(int fd, void *buf, size_t size);
void						ft_puterror(void);
#endif
