/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 08:28:47 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/03 02:12:44 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_app		*app;

	if (argc != 2)
		ft_puterror();
	app = 0;
	init_app(&app, argc, argv);
	run_app(app);
	free_app(&app);
	return (0);
}
