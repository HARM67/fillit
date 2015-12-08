/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 07:51:26 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/02 16:02:57 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_vecteur	set_vecteur(char x, char y)
{
	t_vecteur v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vecteur	add_vecteur(t_vecteur v1, t_vecteur v2)
{
	t_vecteur v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return (v);
}

t_vecteur	invert_vecteur(t_vecteur v)
{
	v.x = -v.x;
	v.y = -v.y;
	return (v);
}
