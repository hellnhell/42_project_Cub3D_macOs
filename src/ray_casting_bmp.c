/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:45:10 by emartin-          #+#    #+#             */
/*   Updated: 2020/06/16 12:28:01 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

void	init_bmp(t_tab *t)
{
	t->line_height = (int)(t->sheight / t->perpwalldist);
	t->drawstart = -t->line_height / 2 + t->sheight / 2;
	if (t->drawstart < 0)
		t->drawstart = 0;
	t->drawend = t->line_height / 2 + t->sheight / 2;
	if (t->drawend >= t->sheight)
		t->drawend = t->sheight - 1;
}

void	ray_casting_bmp(t_tab *t)
{
	t->x = -1;
	t->sprite_on = 0;
	t->img = mlx_new_image(t->mlx, t->swidth, t->sheight);
	t->img_ptr = mlx_get_data_addr(t->img, &t->bpp, &t->sl, &t->endian);
	if (t->texture == 1)
		draw_sky(t);
	tex_walls(t);
	while (++t->x < t->swidth)
	{
		ray_casting_init(t, t->x);
		init_bmp(t);
		tex_walls(t);
		draw_wall(t->x, t->drawstart - 1, t->drawend, t);
		t->zbuffer[t->x] = t->perpwalldist;
	}
	if (t->sprite_on == 1)
		draw_sprites(t);
	mlx_put_image_to_window(t->mlx, t->window, t->img, 0, 0);
	save_bmp(t);
	mlx_destroy_image(t->mlx, t->img);
	ft_exit("BMP saved\n");
}
