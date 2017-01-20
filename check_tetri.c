/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 19:13:31 by kyang             #+#    #+#             */
/*   Updated: 2016/12/10 16:58:56 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*nexttest(int *com, int total, int test)
{
	if (test == 1)
	{
		if (total < 3)
			com = addnext(com, 4);
		else if (total == 3)
			com = addarray(1, 5, 9, 13);
		else
			com = addnext(com, 1);
	}
	else
	{
		if ((total + 1) % 3 == 0)
			com = addnext(com, 2);
		else
			com = addnext(com, 1);
	}
	return (com);
}

static int		check_line(int pos[4])
{
	int		*com;
	int		count;
	int		total;

	total = -1;
	com = (int *)malloc(sizeof(int) * 4);
	if (!com)
		return (0);
	com = addarray(1, 2, 3, 4);
	while (++total < 8)
	{
		count = 0;
		while (pos[count] == com[count])
		{
			if (count == 3)
			{
				free(com);
				return (1);
			}
			count++;
		}
		com = nexttest(com, total, 1);
	}
	free(com);
	return (0);
}

static int		check_square(int pos[4])
{
	int		*com;
	int		count;
	int		total;

	total = -1;
	com = (int *)malloc(sizeof(int) * 4);
	if (!com)
		return (0);
	com = addarray(1, 2, 5, 6);
	while (++total < 9)
	{
		count = 0;
		while (pos[count] == com[count])
		{
			if (count == 3)
			{
				free(com);
				return (1);
			}
			count++;
		}
		com = nexttest(com, total, 0);
	}
	free(com);
	return (0);
}

static int		check_piece(int pos[4])
{
	int		errorcheck;

	errorcheck = check_line(pos);
	if (errorcheck == 1)
		return (1);
	errorcheck = check_square(pos);
	if (errorcheck == 1)
		return (1);
	errorcheck = check_lshape(pos);
	if (errorcheck == 1)
		return (1);
	errorcheck = check_tshape(pos);
	if (errorcheck == 1)
		return (1);
	errorcheck = check_zshape(pos);
	if (errorcheck == 1)
		return (1);
	return (0);
}

int				check_valid_tetri(char *file)
{
	int		tcount;
	int		temp;
	int		poss[5];

	tcount = 0;
	temp = -1;
	while (tcount < 16)
	{
		if (file[tcount] != '.' && file[tcount] != '#')
			return (0);
		if (file[tcount] == '#')
		{
			poss[++temp] = tcount + 1;
			if (temp > 3)
				return (0);
		}
		tcount++;
	}
	if (temp != 3)
		return (0);
	return (check_piece(poss));
}
