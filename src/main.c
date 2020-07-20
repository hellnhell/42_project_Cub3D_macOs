/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:28:42 by emartin-          #+#    #+#             */
/*   Updated: 2020/07/17 18:10:12 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

int		ft_exit(char *mess)
{
	ft_putstr_fd(mess, 1);
	exit(1);
}

void	mlx_win_init(t_tab *t)
{
	t->mlx = mlx_init();
	t->window = mlx_new_window(t->mlx, t->swidth, t->sheight, "cub3d");
	mlx_hook(t->window, 17, 0, ft_exit, t);
	mlx_hook(t->window, 2, 0, ft_press_key, t);
	mlx_hook(t->window, 3, 0, ft_release_key, t);
	init_variables(t);
}

void	init_variables(t_tab *t)
{
	t->help = 1;
	t->move_speed = 0.1;
	t->rot_speed = 0.08;
	t->up = 0;
	t->down = 0;
	t->left = 0;
	t->right = 0;
	t->x_tex = 0;
	t->y_tex = 0;
	t->texture = 1;
	t->sprite_on = 0;
	t->sprite_count = 45;
	t->sprite_posx = 0;
	t->sprite_posy = 0;
}

int		main(int argc, char **argv)
{
	t_tab	*t;
	int		fd;

	if (argc < 2)
		ft_exit("ERROR\nArgs number error");
	if (!(t = malloc(sizeof(t_tab))))
		ft_exit("ERROR\nMalloc struct error");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit("ERROR\nNo such file");
	if (!(ft_get_spec(t, fd) == 1))
		ft_exit("ERROR\nReading map error");
	if (!(t->zbuffer = malloc(sizeof(double) * t->swidth)))
		ft_exit("ERROR\nBuffer error");
	mlx_win_init(t);
	load_textures(t);
	if (argc == 3 && ft_strncmp("--save", argv[2], 6) == 0)
		ray_casting_bmp(t);
	else
		ray_casting(t);
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
	free(t);
	free(t->zbuffer);
	return (0);
}
