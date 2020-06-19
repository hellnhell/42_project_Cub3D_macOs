/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:02:11 by emartin-          #+#    #+#             */
/*   Updated: 2020/06/12 12:45:25 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

static void		calculate_sprites(t_tab *t)
{
	t->inv_det = 1.0 / (t->plane_x * t->dir_y -
		t->dir_x * t->plane_y);
	t->transform_x = t->inv_det * (t->dir_y *
		t->sprite_x - t->dir_x * t->sprite_y);
	t->transform_y = t->inv_det * (-t->plane_y *
		t->sprite_x + t->plane_x * t->sprite_y);
	t->sprite_screen_x = (int)((t->swidth / 2) *
		(1 + t->transform_x / t->transform_y));
	t->sprite_height = abs((int)(t->sheight / t->transform_y));
	t->draw_start_y = -t->sprite_height / 2 + t->sheight / 2;
	if (t->draw_start_y < 0)
		t->draw_start_y = 0;
	t->draw_end_y = t->sprite_height / 2 + t->sheight / 2;
	if (t->draw_end_y >= t->sheight)
		t->draw_end_y = t->sheight - 1;
	t->sprite_width = abs((int)(t->sheight / t->transform_y));
	t->draw_start_x = -t->sprite_width / 2 + t->sprite_screen_x;
	t->draw_end_x = t->sprite_width / 2 + t->sprite_screen_x;
	if (t->draw_end_x >= t->swidth)
		t->draw_end_x = t->swidth - 1;
}

static void		ft_sprite(t_tab *t, int y, int x)
{
	t->y_tex = abs((y - t->draw_start_y) / (t->sprite_height /
			(double)t->tex[7].h));
	if ((t->tex[7].data[t->y_tex * t->tex[7].sl
		+ t->x_tex * t->tex[7].bpp / 8] != 0))
	{
		ft_memcpy(t->img_ptr + 4 * t->swidth * y + x * 4,
		&t->tex[7].data[t->y_tex * t->tex[7].sl +
		t->x_tex * t->tex[7].bpp / 8], sizeof(int));
	}
}

void			draw_sprites(t_tab *t)
{
	int		x;
	int		y;

	t->sprite_x = (double)t->sprite_posx - t->pos_x;
	t->sprite_y = (double)t->sprite_posy - t->pos_y;
	calculate_sprites(t);
	x = t->draw_start_x - 1;
	while (++x <= t->draw_end_x)
	{
		t->x_tex = (int)((x - t->draw_start_x) / (t->sprite_width /
				(double)t->tex[7].w));
		y = t->draw_start_y;
		if (t->transform_y > 0 && x > 0 && x < t->swidth
			&& t->transform_y < t->zbuffer[x])
		{
			while (++y < t->draw_end_y)
				ft_sprite(t, y, x);
		}
	}
}
