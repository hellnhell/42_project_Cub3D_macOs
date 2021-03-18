/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:25:57 by emartin-          #+#    #+#             */
/*   Updated: 2020/06/16 11:54:01 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strchr(char *s, int c)
{
	unsigned int		pos;

	if (!s || !c)
		return (NULL);
	pos = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			return (&s[pos]);
		pos++;
	}
	return (NULL);
}
