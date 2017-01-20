/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 01:03:52 by eliu              #+#    #+#             */
/*   Updated: 2016/12/14 19:44:09 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_checkcanadd(char **tetra, char **map, int t[])
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i + MI] && tetra[i])
	{
		if (tetra[i][j] == '#' && map[i + MI][j + MJ] == '.')
			count++;
		if (tetra[i][j] == '#' && map[i + MI][j + MJ] != '.')
			return (1);
		if (count == 4)
			return (0);
		j++;
		if (!map[i + MI][j + MJ] || !tetra[i][j])
		{
			j = 0;
			i++;
		}
	}
	return (1);
}

char		**ft_solve(char **tetra, char **map, int t[])
{
	int		done;

	MI = TY;
	MJ = TX;
	while (map[MI] && (done = ft_checkcanadd(tetra, map, t)))
	{
		MJ++;
		if (!map[MI][MJ])
		{
			MJ = 0;
			MI++;
		}
	}
	if (done == 0)
	{
		ft_addtetra(tetra, map, t);
		return (map);
	}
	return (NULL);
}

char		**ft_rem_prev(char **map)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	temp = ft_letter(map);
	temp--;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == temp)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int			ft_output(char ***str, char **map, char **temp, int t[])
{
	while (str[++I] != NULL)
	{
		TX = 0;
		TY = 0;
		while (!(map = ft_solve(str[I], temp, t)))
		{
			TX++;
			while (temp[TY][TX] && temp[TY][TX] != '.')
				TX++;
			GO_TO_NEXT_LINE;
			if (temp[TY] == NULL)
			{
				TY = find(temp, 'y', 100);
				TX = find(temp, 'x', 100);
				temp = ft_rem_prev(temp);
				I--;
				if (I < 0)
					return (1);
				GO_TO_NEXT_LINE;
			}
		}
	}
	ft_print(map);
	return (0);
}
