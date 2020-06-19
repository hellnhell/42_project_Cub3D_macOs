/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:40:31 by emartin-          #+#    #+#             */
/*   Updated: 2020/06/12 12:43:06 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

int		ft_get_coord(t_tab *t)
{
	int	col;
	int line;

	line = 0;
	col = 0;
	t->player_pos = 0;
	while (t->map[line])
	{
		while (t->map[line][col] != '\0')
		{
			if (ft_check_in_set_char(t->map[line][col], "WESN") == 1)
			{
				t->pos_x = line;
				t->pos_y = col;
				t->dir = t->map[line][col];
				t->map[line][col] = '0';
				t->player_pos = 1;
				return (1);
			}
			col++;
		}
		col = 0;
		line++;
	}
	return (0);
}

void	ft_correct(char **line, t_tab *t, int fd)
{
	char	*aux;

	aux = ft_strtrim(*line, " ");
	if (*aux)
	{
		t->map[0] = ft_strdup(*line);
		return ;
	}
	free(aux);
	while (get_next_line(fd, line))
	{
		aux = ft_strtrim(*line, " ");
		if (*aux)
		{
			t->map[0] = ft_strdup(*line);
			break ;
		}
		free(aux);
	}
}

void	ft_get_map(t_tab *t, char **line, int fd)
{
	int		map_line;

	if (!(t->map = (char **)ft_calloc(1000000, sizeof(char *))))
		ft_exit("ERROR\nMap mem error");
	map_line = 1;
	ft_correct(line, t, fd);
	while (get_next_line(fd, line) == 1)
	{
		t->map[map_line] = ft_strdup(*line);
		map_line++;
		free(*line);
	}
	t->map[map_line] = ft_strdup(*line);
	t->map[++map_line] = ft_strdup(" ");
	free(*line);
}

void	ft_get_res(char *line, t_tab *t)
{
	int		i_line;

	i_line = 0;
	while (!ft_isdigit(line[i_line]))
		i_line++;
	t->swidth = ft_atoi(line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	i_line++;
	t->sheight = ft_atoi(line + i_line);
}

int		ft_get_col(char *line)
{
	int		i_line;
	char	*color;
	int		i_color;
	int		col;

	if (!(color = (char *)ft_calloc(10, sizeof(char))))
		return (0);
	i_color = 0;
	i_line = 2;
	while (line[i_line])
	{
		while (ft_isdigit(line[i_line]) == 0 && line[i_line])
			i_line++;
		while (ft_isdigit(line[i_line]) == 1 && line[i_line])
			color[i_color++] = line[i_line++];
	}
	if (ft_atoi(color) < 0 || ft_atoi(color) > 255255255)
		return (0);
	col = ft_atoi(color);
	free(color);
	return (col);
}
