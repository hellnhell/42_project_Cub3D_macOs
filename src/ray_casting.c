/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:52:29 by emartin-          #+#    #+#             */
/*   Updated: 2020/06/12 11:50:10 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

void		dda_init(t_tab *t)
{
	t->deltadist_x = sqrt(1 + (t->raydir_y * t->raydir_y)
					/ (t->raydir_x * t->raydir_x));
	t->deltadist_y = sqrt(1 + (t->raydir_x * t->raydir_x)
					/ (t->raydir_y * t->raydir_y));
	if (t->raydir_x < 0)
	{
		t->step_x = -1;
		t->sidedist_x = (t->raypos_x - t->map_x) * t->deltadist_x;
	}
	else
	{
		t->step_x = 1;
		t->sidedist_x = (t->map_x + 1.0 - t->raypos_x) * t->deltadist_x;
	}
	if (t->raydir_y < 0)
	{
		t->step_y = -1;
		t->sidedist_y = (t->raypos_y - t->map_y) * t->deltadist_y;
	}
	else
	{
		t->step_y = 1;
		t->sidedist_y = (t->map_y + 1.0 - t->raypos_y) * t->deltadist_y;
	}
}

void		dda(t_tab *t)
{
	t->hit = 0;
	while (t->hit == 0)
	{
		if (t->sidedist_x < t->sidedist_y)
		{
			t->sidedist_x += t->deltadist_x;
			t->map_x += t->step_x;
			t->side = 0;
		}
		else
		{
			t->sidedist_y += t->deltadist_y;
			t->map_y += t->step_y;
			t->side = 1;
		}
		if (t->map[t->map_x][t->map_y] == '1')
			t->hit = 1;
		if (t->map[t->map_x][t->map_y] == '2')
		{
			t->sprite_on = 1;
			t->sprite_posx = t->map_x;
			t->sprite_posy = t->map_y;
		}
	}
}

void		ray_casting_init(t_tab *t, int x)
{
	t->camera_x = 2 * x / (double)t->swidth - 1;
	t->raypos_x = t->pos_x;
	t->raypos_y = t->pos_y;
	t->raydir_x = t->dir_x + t->plane_x * t->camera_x;
	t->raydir_y = t->dir_y + t->plane_y * t->camera_x;
	t->map_x = (int)t->raypos_x;
	t->map_y = (int)t->raypos_y;
	t->sprite_hit = 0;
	t->sprite_count = 45;
	t->sprite_width = 0;
	t->sprite_height = 0;
	dda_init(t);
	dda(t);
	if (t->side == 0)
		t->perpwalldist = (t->map_x - t->raypos_x + (1 - t->step_x) / 2)
						/ t->raydir_x;
	else
		t->perpwalldist = (t->map_y - t->raypos_y + (1 - t->step_y) / 2)
						/ t->raydir_y;
}

void		ray_casting(t_tab *t)
{
	t->x = -1;
	t->sprite_on = 0;
	t->img = mlx_new_image(t->mlx, t->swidth, t->sheight);
	t->img_ptr = mlx_get_data_addr(t->img, &t->bpp, &t->sl, &t->endian);
	if (t->texture == 1)
		draw_sky(t);
	while (++t->x < t->swidth)
	{
		ray_casting_init(t, t->x);
		t->line_height = (int)(t->sheight / t->perpwalldist);
		t->drawstart = -t->line_height / 2 + t->sheight / 2;
		if (t->drawstart < 0)
			t->drawstart = 0;
		t->drawend = t->line_height / 2 + t->sheight / 2;
		if (t->drawend >= t->sheight)
			t->drawend = t->sheight - 1;
		tex_walls(t);
		draw_wall(t->x, t->drawstart - 1, t->drawend, t);
		t->zbuffer[t->x] = t->perpwalldist;
	}
	if (t->sprite_on == 1)
		draw_sprites(t);
	mlx_put_image_to_window(t->mlx, t->window, t->img, 0, 0);
	mlx_destroy_image(t->mlx, t->img);
}
