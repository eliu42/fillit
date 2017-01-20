/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_t_zshape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:24:48 by kyang             #+#    #+#             */
/*   Updated: 2016/12/09 21:22:29 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				*addnext(int *com, int add)
{
	int		count;

	count = 0;
	while (count < 4)
	{
		com[count] += add;
		count++;
	}
	return (com);
}

static int		*nexttest_t(int *com, int total)
{
	if (total < 11)
	{
		if (total == 5)
			com = addarray(2, 5, 6, 10);
		else if ((total + 1) % 3 == 0)
			com = addnext(com, 2);
		else
			com = addnext(com, 1);
	}
	else
	{
		if (total == 11)
			com = addarray(1, 2, 3, 6);
		else if (total == 17)
			com = addarray(2, 5, 6, 7);
		else if ((total + 1) % 2 == 0)
			com = addnext(com, 3);
		else
			com = addnext(com, 1);
	}
	return (com);
}

static int		*nexttest_z(int *com, int total)
{
	if (total < 11)
	{
		if (total == 5)
			com = addarray(2, 3, 5, 6);
		else if ((total + 1) % 2 == 0)
			com = addnext(com, 3);
		else
			com = addnext(com, 1);
	}
	else
	{
		if (total == 11)
			com = addarray(2, 5, 6, 9);
		else if (total == 17)
			com = addarray(1, 5, 6, 10);
		else if ((total + 1) % 3 == 0)
			com = addnext(com, 2);
		else
			com = addnext(com, 1);
	}
	return (com);
}

int				check_tshape(int pos[4])
{
	int		total;
	int		count;
	int		*com;

	total = -1;
	com = (int *)malloc(sizeof(int) * 4);
	if (!com)
		return (0);
	com = addarray(1, 5, 6, 9);
	while (++total < 24)
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
		com = nexttest_t(com, total);
	}
	free(com);
	return (0);
}

int				check_zshape(int pos[4])
{
	int		total;
	int		count;
	int		*com;

	total = -1;
	com = (int *)malloc(sizeof(int) * 4);
	if (!com)
		return (0);
	com = addarray(1, 2, 6, 7);
	while (++total < 24)
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
		com = nexttest_z(com, total);
	}
	free(com);
	return (0);
}
