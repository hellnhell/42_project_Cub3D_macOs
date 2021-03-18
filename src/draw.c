/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:49:56 by emartin-          #+#    #+#             */
/*   Updated: 2020/06/16 11:23:54 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

void		put_pxl_to_img(t_tab *t, int x, int y, int color)
{
	if (t->texture == 1)
	{
		t->y_tex = (y - (t->sheight - t->line_height) / 2) / (t->line_height /
					(double)t->tex[t->id].h);
		ft_memcpy(t->img_ptr + t->sl * y + x * (t->bpp / 8), t->tex[t->id].data
				+ t->y_tex * t->tex[t->id].sl +
				t->x_tex * t->tex[t->id].bpp / 8, sizeof(int));
	}
	else if (x < t->swidth && y < t->sheight)
		ft_memcpy(t->img_ptr + t->sl * y + x * t->bpp,
				&color, sizeof(int));
}

void		draw_wall(int x, int drawstart, int drawend, t_tab *t)
{
	if (t->texture == 1)
	{
		if (t->side == 0)
			t->wall_x = t->raypos_y + t->perpwalldist * t->raydir_y;
		else
			t->wall_x = t->raypos_x + t->perpwalldist * t->raydir_x;
		t->wall_x -= floor(t->wall_x);
		t->x_tex = (int)(t->wall_x * (double)(t->tex[t->id].w));
	}
	while (++drawstart < drawend)
		put_pxl_to_img(t, x, drawstart, t->color);
}

void		draw_sky(t_tab *t)
{
	t->x_tex = 0;
	while (t->x_tex < t->swidth)
	{
		t->y_tex = 0;
		while (t->y_tex < t->sheight / 2)
		{
			ft_memcpy(t->img_ptr + t->sl * t->y_tex + t->x_tex * 4,
					&t->tex[6].data[t->y_tex % t->tex[6].h * t->tex[6].sl +
					t->x_tex % t->tex[6].w * t->tex[6].bpp / 8], sizeof(int));
			t->y_tex++;
		}
		t->x_tex++;
	}
	draw_floor(t);
}

void		draw_floor(t_tab *t)
{
	t->x_tex = 0;
	while (t->x_tex < t->swidth)
	{
		t->y_tex = t->sheight / 2;
		while (t->y_tex < t->sheight)
		{
			ft_memcpy(t->img_ptr + t->sl * t->y_tex + t->x_tex * 4,
					&t->tex[5].data[t->y_tex % t->tex[5].h * t->tex[5].sl +
					t->x_tex % t->tex[5].w * t->tex[5].bpp / 8], sizeof(int));
			t->y_tex++;
		}
		t->x_tex++;
	}
}
