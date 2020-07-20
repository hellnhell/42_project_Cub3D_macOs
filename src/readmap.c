/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:10:57 by emartin-          #+#    #+#             */
/*   Updated: 2020/07/15 18:20:24 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

static void	get_spec(t_tab *t)
{
	ft_get_coord(t);
	if (t->player_pos == 0)
		ft_exit("ERROR\nPlayer pos error");
	ft_check_limits(t);
	ft_get_camangle(t);
	map_config_check(t);
	if (!t->col_floor || t->swidth > 2560 || t->sheight > 1400 || !t->no_tex
		|| t->swidth <= 0 || t->sheight <= 0 ||
		!t->we_tex || !t->ea_tex || !t->so_tex || !t->path_sprite)
		ft_exit("ERROR\nMap seizures error");
	if (ft_strncmp("./textures/", t->no_tex, 11) != 0)
		ft_exit("ERROR\nN");
	if (ft_strncmp("./textures/", t->ea_tex, 11) != 0)
		ft_exit("ERROR\nE");
	if (ft_strncmp("./textures/", t->we_tex, 11) != 0)
		ft_exit("ERROR\nW");
	if (ft_strncmp("./textures/", t->so_tex, 11) != 0)
		ft_exit("ERROR\nS");
	if (ft_strncmp("./textures/", t->path_sprite, 11) != 0)
		ft_exit("ERROR\nSPRITE");
}

void		get_spec_floor(t_tab *t, char *line)
{
	(line[0] == 'S' && line[1] == ' ')
		? t->path_sprite = ft_strdup(line + 2) : 0;
	(line[0] == 'F' && line[1] == ' ')
		? t->col_floor = ft_get_col(line) : 0;
}

int			ft_get_spec(t_tab *t, int fd)
{
	char *tmp;
	char *line;

	while (get_next_line(fd, &line) == 1)
	{
		tmp = line;
		(line[0] == 'R' && line[1] == ' ') ? ft_get_res(line, t) : 0;
		(line[0] == 'N' && line[1] == 'O' && line[2] == ' ') ?
				t->no_tex = ft_strdup(line + 3) : 0;
		(line[0] == 'S' && line[1] == 'O' && line[2] == ' ') ?
				t->so_tex = ft_strdup(line + 3) : 0;
		(line[0] == 'W' && line[1] == 'E' && line[2] == ' ') ?
				t->we_tex = ft_strdup(line + 3) : 0;
		(line[0] == 'E' && line[1] == 'A' && line[2] == ' ') ?
				t->ea_tex = ft_strdup(line + 3) : 0;
		get_spec_floor(t, line);
		(line[0] == '1' || line[0] == 32) ? ft_get_map(t, &line, fd) : 0;
		free(tmp);
	}
	get_spec(t);
	close(fd);
	free(line);
	return (1);
}

static void	position(t_tab *t)
{
	if (t->dir == 'N')
	{
		t->dir_x = -1;
		t->dir_y = 0;
		t->plane_x = 0;
		t->plane_y = 0.66;
	}
	else if (t->dir == 'W')
	{
		t->dir_x = 0;
		t->dir_y = -1;
		t->plane_x = -0.66;
		t->plane_y = 0;
	}
}

int			ft_get_camangle(t_tab *t)
{
	if (t->dir == 'N')
		position(t);
	else if (t->dir == 'W')
		position(t);
	else if (t->dir == 'S')
	{
		t->dir_x = 1;
		t->dir_y = 0;
		t->plane_x = 0;
		t->plane_y = -0.66;
	}
	else if (t->dir == 'E')
	{
		t->dir_x = 0;
		t->dir_y = 1;
		t->plane_x = 0.66;
		t->plane_y = 0;
	}
	else
		return (0);
	return (1);
}
