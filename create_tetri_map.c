/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:27:10 by kyang             #+#    #+#             */
/*   Updated: 2016/12/10 00:33:54 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				**topleft_cord(int **xy_cord)
{
	int		count;
	int		count1;
	int		zero;

	zero = -1;
	count1 = 0;
	while (count1 != 2)
	{
		count = -1;
		while (++count < 4)
			if (xy_cord[count][count1] == 0)
				zero = 0;
		if (zero == 0)
		{
			zero = -1;
			count1++;
		}
		else
		{
			count = -1;
			while (++count < 4)
				xy_cord[count][count1] += zero;
		}
	}
	return (xy_cord);
}

int				**fill_cord(char **map)
{
	int			**xy_cord;
	int			y;
	int			x;
	int			count;

	y = -1;
	count = 0;
	xy_cord = create_xycord();
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (map[y][x] == '#')
			{
				xy_cord[count][0] = x;
				xy_cord[count][1] = y;
				count++;
			}
		}
	}
	xy_cord = topleft_cord(xy_cord);
	return (xy_cord);
}

char			**pushtop(char **map)
{
	int			**xy_cord;
	int			x;
	int			y;
	int			count;
	char		**new_map;

	xy_cord = fill_cord(map);
	x = find_max(xy_cord, 0);
	y = find_max(xy_cord, 1);
	new_map = (char **)malloc(sizeof(char *) * y + 1);
	if (!new_map)
		return (NULL);
	new_map = fill_newmap(new_map, xy_cord, x, y);
	count = -1;
	free_map(map);
	return (new_map);
}

char			**fill_tetri_map(char *tetri)
{
	int			count;
	int			count1;
	int			count2;
	char		**map;

	map = (char **)malloc(sizeof(char *) * 5);
	if (!map)
		return (NULL);
	map[4] = NULL;
	count = -1;
	count2 = 0;
	while (++count < 4)
	{
		count1 = -1;
		map[count] = ft_strnew(4);
		while (++count1 < 4)
		{
			map[count][count1] = tetri[count2];
			count2++;
		}
		map[count][count1] = '\0';
	}
	return (map);
}

char			**create_tetri_map(char *tetri)
{
	char		**map;
	int			count;

	map = fill_tetri_map(tetri);
	count = -1;
	map = pushtop(map);
	return (map);
}
