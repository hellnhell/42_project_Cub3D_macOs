/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:51:22 by emartin-          #+#    #+#             */
/*   Updated: 2020/07/14 17:40:17 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

int		ft_press_key(int key, t_tab *t)
{
	if (key == KEY_W || key == KEY_UP)
		t->up = 1;
	if (key == KEY_S || key == KEY_DOWN)
		t->down = 1;
	if (key == KEY_LEFT)
		t->rot_left = 1;
	if (key == KEY_A)
		t->left = 1;
	if (key == KEY_RIGHT)
		t->rot_right = 1;
	if (key == KEY_D)
		t->right = 1;
	else if (key == KEY_TAB)
		t->move_speed = 0.1;
	else
		ft_press_key2(key, t);
	return (0);
}

int		ft_release_key(int key, t_tab *t)
{
	if (key == KEY_W || key == KEY_UP)
		t->up = 0;
	if (key == KEY_S || key == KEY_DOWN)
		t->down = 0;
	if (key == KEY_LEFT)
		t->rot_left = 0;
	if (key == KEY_A)
		t->left = 0;
	if (key == KEY_RIGHT)
		t->rot_right = 0;
	if (key == KEY_D)
		t->right = 0;
	else if (key == KEY_TAB)
		t->move_speed = 0.05;
	if (key == KEY_ESC)
		ft_exit("");
	return (0);
}

void	move_side(t_tab *t)
{
	if (t->left == 1)
	{
		if (t->map[(int)(t->pos_x - t->dir_y * t->move_speed)]
			[(int)(t->pos_y)] == '0')
			t->pos_x -= t->dir_y * t->move_speed;
		if (t->map[(int)(t->pos_x)][(int)(t->pos_y + t->dir_x
		* t->move_speed)] == '0')
			t->pos_y += t->dir_x * t->move_speed;
	}
	if (t->right == 1)
	{
		if (t->map[(int)(t->pos_x + t->dir_y * t->move_speed)]
			[(int)(t->pos_y)] == '0')
			t->pos_x += t->dir_y * t->move_speed;
		if (t->map[(int)(t->pos_x)][(int)(t->pos_y - t->dir_x
			* t->move_speed)] == '0')
			t->pos_y -= t->dir_x * t->move_speed;
	}
}

void	rotate(t_tab *t)
{
	if (t->rot_right == 1)
	{
		t->old_dir_x = t->dir_x;
		t->dir_x = t->dir_x * cos(-t->rot_speed) - t->dir_y
				* sin(-t->rot_speed);
		t->dir_y = t->old_dir_x * sin(-t->rot_speed) + t->dir_y
				* cos(-t->rot_speed);
		t->old_plane_x = t->plane_x;
		t->plane_x = t->plane_x * cos(-t->rot_speed) - t->plane_y
				* sin(-t->rot_speed);
		t->plane_y = t->old_plane_x * sin(-t->rot_speed) + t->plane_y
				* cos(-t->rot_speed);
	}
	if (t->rot_left == 1)
	{
		t->old_dir_x = t->dir_x;
		t->dir_x = t->dir_x * cos(t->rot_speed) - t->dir_y * sin(t->rot_speed);
		t->dir_y = t->old_dir_x * sin(t->rot_speed) + t->dir_y
				* cos(t->rot_speed);
		t->old_plane_x = t->plane_x;
		t->plane_x = t->plane_x * cos(t->rot_speed) - t->plane_y
				* sin(t->rot_speed);
		t->plane_y = t->old_plane_x * sin(t->rot_speed) + t->plane_y
				* cos(t->rot_speed);
	}
}

int		move(t_tab *t)
{
	if (t->up == 1)
	{
		if (t->map[(int)(t->pos_x + t->dir_x * t->move_speed)]
			[(int)(t->pos_y)] == '0')
			t->pos_x += t->dir_x * t->move_speed;
		if (t->map[(int)(t->pos_x)][(int)(t->pos_y + t->dir_y
			* t->move_speed)] == '0')
			t->pos_y += t->dir_y * t->move_speed;
	}
	if (t->down == 1)
	{
		if (t->map[(int)(t->pos_x - t->dir_x * t->move_speed + 0.1)]
			[(int)(t->pos_y)] == '0')
			t->pos_x -= t->dir_x * t->move_speed;
		if (t->map[(int)(t->pos_x)][(int)(t->pos_y - t->dir_y
			* t->move_speed)] == '0')
			t->pos_y -= t->dir_y * t->move_speed;
	}
	rotate(t);
	move_side(t);
	ray_casting(t);
	if (t->help == 1)
		help_text(t);
	return (0);
}
