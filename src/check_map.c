/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:18:55 by emartin-          #+#    #+#             */
/*   Updated: 2020/07/07 20:00:49 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

void		ft_check_first_line(t_tab *t)
{
	int		j;

	j = 0;
	while (t->map[0][j] != '\0')
	{
		while (t->map[0][j] == '0' || t->map[0][j] == '2')
		{
			if (ft_strchr("02", t->map[0][j + 1]))
				ft_exit("ERROR\nWrong fl 1");
			else if (ft_strchr("02", t->map[0][j - 1]))
				ft_exit("ERROR\nWrong fl 2");
			else if (!(ft_strchr("\0", t->map[1][j])))
				ft_exit("ERROR\nWrong fl 3");
		}
		j++;
	}
}

void		ft_border_errors(t_tab *t, int i, int j)
{
	if (!(ft_strchr("012", t->map[i][j + 1])))
		ft_exit("ERROR\nWrong character 1");
	else if (!(ft_strchr("012\n", t->map[i][j - 1])))
		ft_exit("ERROR\nWrong character 2");
	else if (!(ft_strchr("012", t->map[i + 1][j])))
		ft_exit("ERROR\nWrong character 3");
	else if (!(ft_strchr("012", t->map[i - 1][j])))
		ft_exit("ERROR\nWrong character 4");
	else if (ft_strchr("02", t->map[i][0]))
		ft_exit("ERROR\nWrong character 5");
}

void		ft_check_limits(t_tab *t)
{
	int		i;
	int		j;

	i = -1;
	while (t->map[++i] != NULL)
	{
		j = -1;
		while (t->map[i][++j] != '\0')
		{
			if (i == 0)
				ft_check_first_line(t);
			else if (t->map[i][j] == '0' || t->map[i][j] == '2')
				ft_border_errors(t, i, j);
		}
	}
}

int			ft_check_in_set_char(char to_test, char *dataset)
{
	int	i;

	i = 0;
	while (dataset[i])
	{
		if (dataset[i] == to_test)
			return (1);
		i++;
	}
	return (0);
}
