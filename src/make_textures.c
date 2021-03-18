/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:53:51 by emartin-          #+#    #+#             */
/*   Updated: 2020/07/17 18:14:14 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

void	map_config_check(t_tab *t)
{
	if (!(t->so_tex))
		ft_exit("\nError\nNo SO path in the .cub \n");
	if (!(t->no_tex))
		ft_exit("\nError\nNo NO path in the .cub \n");
	if (!(t->ea_tex))
		ft_exit("\nError\nNo EA path in the .cub \n");
	if (!(t->we_tex))
		ft_exit("\nError\nNo WE path in the .cub \n");
	if (!(t->path_sprite))
		ft_exit("\nError\nNo SPRITE path in the .cub \n");
	if (!(t->swidth || t->sheight))
		ft_exit("\nError\nNo RESOLUTION DATA in the .cub \n");
}

void	tex_walls(t_tab *t)
{
	if (t->side == 0 && t->raydir_x > 0)
		t->id = 0;
	else if (t->side == 0 && t->raydir_x < 0)
		t->id = 1;
	else if (t->side == 1 && t->raydir_y > 0)
		t->id = 2;
	else if (t->side == 1 && t->raydir_y < 0)
		t->id = 3;
}

void	load_textures(t_tab *t)
{
	if (!(t->tex[0].img = mlx_xpm_file_to_image(t->mlx, t->no_tex, &t->tex[0].w,
					&t->tex[0].h)))
		ft_exit("ERROR\nNO text doesn't exist");
	t->tex[0].data = mlx_get_data_addr(t->tex[0].img, &t->tex[0].bpp,
					&t->tex[0].sl, &t->tex[0].endian);
	if (!(t->tex[1].img = mlx_xpm_file_to_image(t->mlx, t->so_tex, &t->tex[1].w,
					&t->tex[1].h)))
		ft_exit("ERROR\nSO text doesn't exist");
	t->tex[1].data = mlx_get_data_addr(t->tex[1].img, &t->tex[1].bpp,
					&t->tex[1].sl, &t->tex[1].endian);
	if (!(t->tex[2].img = mlx_xpm_file_to_image(t->mlx, t->we_tex, &t->tex[2].w,
					&t->tex[2].h)))
		ft_exit("ERROR\nWE text doesn't exist");
	t->tex[2].data = mlx_get_data_addr(t->tex[2].img, &t->tex[2].bpp,
					&t->tex[2].sl, &t->tex[2].endian);
	if (!(t->tex[3].img = mlx_xpm_file_to_image(t->mlx, t->ea_tex, &t->tex[3].w,
					&t->tex[3].h)))
		ft_exit("ERROR\nEA text doesn't exist");
	t->tex[3].data = mlx_get_data_addr(t->tex[3].img, &t->tex[3].bpp,
					&t->tex[3].sl, &t->tex[3].endian);
	load_textures_ext(t);
}

void	load_textures_ext(t_tab *t)
{
	if (!(t->tex[5].img = mlx_xpm_file_to_image(t->mlx, "textures/white.xpm",
					&t->tex[5].w, &t->tex[5].h)))
		ft_exit("ERROR\nCeeling text doesn't exist");
	t->tex[5].data = mlx_get_data_addr(t->tex[5].img, &t->tex[5].bpp,
					&t->tex[5].sl, &t->tex[5].endian);
	if (!(t->tex[6].img = mlx_xpm_file_to_image(t->mlx, "textures/white_s.xpm",
					&t->tex[6].w, &t->tex[6].h)))
		ft_exit("ERROR\nFloor text doesn't exist");
	t->tex[6].data = mlx_get_data_addr(t->tex[6].img, &t->tex[6].bpp,
					&t->tex[6].sl, &t->tex[6].endian);
	if (!(t->tex[7].img = mlx_xpm_file_to_image(t->mlx, t->path_sprite,
					&t->tex[7].w, &t->tex[7].h)))
		ft_exit("ERROR\nSprite text doesn't exist");
	t->tex[7].data = mlx_get_data_addr(t->tex[7].img, &t->tex[7].bpp,
					&t->tex[7].sl, &t->tex[7].endian);
}
