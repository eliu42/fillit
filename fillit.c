/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:00:18 by kyang             #+#    #+#             */
/*   Updated: 2016/12/10 19:29:12 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char					*addtetri(char *tetri)
{
	if (tetri != NULL)
	{
		ft_strdel(&tetri);
		tetri = ft_strnew(16);
	}
	else
		tetri = ft_strnew(16);
	return (tetri);
}

char					*add(char *str, char text[1])
{
	int			len;
	char		*temp;

	if (str == NULL)
	{
		temp = ft_strnew(2);
		temp[0] = text[0];
	}
	else
	{
		len = ft_strlen(str);
		temp = ft_strnew(len + 1);
		temp = ft_strcat(temp, str);
		temp = ft_strncat(temp, text, 1);
	}
	str = temp;
	return (str);
}

char					**addlist(char *tetri)
{
	char		**node;

	if (!check_valid_tetri(tetri))
	{
		free(tetri);
		return (NULL);
	}
	node = create_tetri_map(tetri);
	return (node);
}

char					***makelist(char *str, char ***start, int count)
{
	int			count1;
	int			count_map;
	char		*tetri;

	count_map = -1;
	count1 = 15;
	tetri = NULL;
	while (str[++count] != '\0')
	{
		if (count1 == 15)
		{
			tetri = addtetri(tetri);
			count1 = -1;
		}
		if (str[count] != '\n')
			tetri[++count1] = str[count];
		if (count1 == 15)
		{
			if ((start[++count_map] = addlist(tetri)) == NULL)
				return (NULL);
		}
	}
	start[count_map + 1] = NULL;
	return (start);
}

int						fillit(char *file, int fd, char ***start, int t[])
{
	char		text[1];
	char		*str;
	int			size;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	str = NULL;
	while (read(fd, text, 1) != 0)
		str = add(str, text);
	if (!check_str(str))
		return (-1);
	start = makelist(str, start, -1);
	if (close(fd) == -1 || start == NULL)
		return (-1);
	size = ft_mapsize(start);
	while ((ft_output(start, ft_createmap(size), ft_createmap(size), t)))
		size++;
	return (0);
}
