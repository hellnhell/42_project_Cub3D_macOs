/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:10:43 by emartin-          #+#    #+#             */
/*   Updated: 2020/06/12 12:06:20 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

void		help_text(t_tab *t)
{
	mlx_string_put(t->mlx, t->window, 10, 10,
			0x0000FF, "Press W A S D to move.");
	mlx_string_put(t->mlx, t->window, 10, 30,
			0x0000FF, "Press <- or -> to turn.");
	mlx_string_put(t->mlx, t->window, 10, 50,
			0x0000FF, "Press H to show or hide this help.");
	mlx_string_put(t->mlx, t->window, 10, 70,
			0x0000FF, "Press SHIFT to run");
	mlx_string_put(t->mlx, t->window, 10, 90,
			0x0000FF, "Press ESC to quit.");
}

void		ft_press_key2(int keycode, t_tab *t)
{
	if (keycode == H_KEY)
	{
		if (t->help == 0)
			t->help = 1;
		else
			t->help = 0;
	}
}
