/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_map_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:50:55 by kyang             #+#    #+#             */
/*   Updated: 2016/12/10 00:40:05 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				find_max(int **xy_cord, int cord)
{
	int		max;
	int		count;

	count = -1;
	max = 0;
	while (++count < 4)
	{
		if (xy_cord[count][cord] > max)
			max = xy_cord[count][cord];
	}
	return (max + 1);
}

void			free_map(char **map)
{
	int		count;

	count = 0;
	while (map[count] != NULL)
	{
		free(map[count]);
		count++;
	}
	map = NULL;
}

int				**create_xycord(void)
{
	int		**xycord;
	int		count;

	xycord = (int **)malloc(sizeof(int *) * 4);
	if (!xycord)
		return (NULL);
	count = -1;
	while (++count < 4)
	{
		xycord[count] = (int *)malloc(sizeof(int) * 2);
		if (!xycord[count])
			return (NULL);
	}
	return (xycord);
}

char			*fill_line(char *line, int **xycord, int y, int x)
{
	int		count;

	count = -1;
	while (++count < 4)
	{
		if (xycord[count][1] == y &&
				xycord[count][0] == x)
		{
			line[x] = '#';
			break ;
		}
		else
			line[x] = '.';
	}
	return (line);
}

char			**fill_newmap(char **newmap, int **xy_cord, int x, int y)
{
	int		count;
	int		count1;

	count = -1;
	while (++count < y)
	{
		newmap[count] = ft_strnew(x + 1);
		count1 = -1;
		while (++count1 < x)
			newmap[count] = fill_line(newmap[count], xy_cord, count, count1);
	}
	newmap[count] = NULL;
	return (newmap);
}
