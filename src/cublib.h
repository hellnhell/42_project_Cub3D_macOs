/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:24:24 by emartin-          #+#    #+#             */
/*   Updated: 2020/07/14 17:48:30 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBLIB_H
# define CUBLIB_H
# include <mlx.h>
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_tex
{
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	int			w;
	int			h;
}				t_tex;

typedef struct	s_tab
{
	t_tex		tex[30];
	char		*map_name;
	void		*mlx;
	void		*window;
	void		*img;
	char		*img_ptr;
	char		**map;
	int			swidth;
	int			sheight;
	int			map_width;
	int			map_height;
	int			nb_lines;
	int			lenline;
	int			bpp;
	int			endian;
	int			sl;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			tex_side;
	int			line_height;
	int			start;
	int			end;
	int			color;
	int			floor_color;
	int			ceiling_color;
	int			up;
	int			down;
	int			left;
	int			right;
	int			help;
	int			x_tex;
	int			y_tex;
	int			id;
	int			texture;
	int			x_floortext;
	int			y_floortext;
	int			w;
	int			h;
	int			x;
	int			y;
	int			initial_pos;
	int			rot_right;
	int			rot_left;
	int			dir;
	double		move_speed;
	double		rot_speed;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		raypos_x;
	double		raypos_y;
	double		raydir_x;
	double		raydir_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	double		old_dir_x;
	double		old_plane_x;
	double		wall_x;
	double		x_floor;
	double		y_floor;
	double		col_floor;
	double		curdist;
	double		weight;
	char		*so_tex;
	char		*no_tex;
	char		*ea_tex;
	char		*we_tex;
	char		*zbuffer;
	int			sprite_count;
	char		*spritee;
	char		*path_sprite;
	int			*spr_buffer;
	double		sprite_x;
	double		sprite_y;
	int			sprite_hit;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			spriteheight;
	int			drawstart;
	int			drawend;
	int			draw_start_x;
	int			draw_end_x;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			sprite_height;
	int			sprite_on;
	int			sprite_posx;
	int			sprite_posy;
	int			player_pos;
}				t_tab;

int				ft_exit(char *mess);
void			init_variables(t_tab *t);
int				ft_press_key(int key, t_tab *t);
int				ft_release_key(int key, t_tab *t);
void			move_side(t_tab *t);
void			rotate(t_tab *t);
int				move(t_tab *t);
void			dda_init(t_tab *t);
void			dda(t_tab *t);
void			ray_casting_init(t_tab *t, int x);
void			ray_casting(t_tab *t);
void			put_pxl_to_img(t_tab *t, int x, int y, int color);
void			draw_wall(int x, int drawstart, int drawend, t_tab *t);
void			draw_sky(t_tab *t);
void			draw_floor(t_tab *t);
void			help_text(t_tab *t);
void			ft_press_key2(int keycode, t_tab *t);
void			tex_walls(t_tab *t);
void			load_textures(t_tab	*t);
void			load_textures_ext(t_tab *t);
void			ray_casting_bmp(t_tab *t);
int				ft_get_spec(t_tab *t, int fd);
int				ft_get_camangle(t_tab *t);
int				ft_get_coord(t_tab *t);
void			ft_get_map(t_tab *t, char **line, int fd);
void			ft_get_res(char *line, t_tab *t);
int				ft_get_col(char *line);
int				save_bmp(t_tab *t);
void			draw_sprites(t_tab *t);
int				get_next_line(int fd, char **line);
void			ft_check_limits(t_tab *t);
void			ft_check_first_line(t_tab *t);
int				ft_check_in_set_char(char to_test, char *dataset);
int				ft_check_map_content_and_size(char **map);
int				ft_check_map_border(char **map);
void			ft_correct_fstline(char **line, t_tab *t, int fd);
void			map_config_check(t_tab *t);
void			ft_border_errors(t_tab *t, int i, int j);
void			init_bmp(t_tab *t);
void			get_spec_floor(t_tab *t, char *line);

# define RGB_WHITE 0xFFFFFF
# define RGB_BLACK 0x000000
# define RGB_RED 0xFF0000
# define RGB_GREEN 0x00FF00
# define RGB_BLUE 0x0000FF
# define RGB_YELLOW 0xFFFF00
# define RGB_CHOCOLATE 0xD2691E
# define RGB_GRAY 0x808080
# define RGB_DARKGRAY 0x2F4F4F
# define RGB_INDIGO 0x4B0082
# define RGB_TOMATO 0xFF6347
# define RGB_DARKBLUE 0x00008B
# define RGB_BLUESKY 0x87FFFA

# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
#endif
