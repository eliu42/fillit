/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 00:01:53 by eliu              #+#    #+#             */
/*   Updated: 2016/12/10 00:39:03 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_mapsize(char ***str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
		i++;
	while (len * len < i * 4)
		len++;
	return (len);
}

char	**ft_createmap(int size)
{
	int		i;
	char	**str;

	i = 0;
	str = (char**)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		str[i] = ft_strnew(size);
		ft_memset(str[i], '.', size);
		str[i][size] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}

void	ft_print(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
		ft_putendl(map[i]);
}

char	ft_letter(char **map)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	temp = '@';
	while (map[i])
	{
		if (map[i][j] > temp)
			temp = map[i][j];
		j++;
		if (!map[i][j])
		{
			j = 0;
			i++;
		}
	}
	return (++temp);
}

char	**ft_addtetra(char **tetra, char **map, int t[])
{
	int		i;
	int		j;
	char	letter;

	i = 0;
	j = 0;
	letter = ft_letter(map);
	while (map[i + MI] && tetra[i])
	{
		if (tetra[i][j] == '#')
			map[i + MI][j + MJ] = letter;
		j++;
		if (!map[i + MI][j + MJ] || !tetra[i][j])
		{
			j = 0;
			i++;
		}
	}
	return (map);
}
