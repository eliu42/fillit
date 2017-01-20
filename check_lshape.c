/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lshape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:33:18 by kyang             #+#    #+#             */
/*   Updated: 2016/11/30 16:38:22 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				*addarray(int fir, int sec, int thr, int four)
{
	int		*com;

	com = (int *)malloc(sizeof(int) * 4);
	com[0] = fir;
	com[1] = sec;
	com[2] = thr;
	com[3] = four;
	return (com);
}

static int		*nexttest_lr(int *com, int total)
{
	if (total == 23)
		com = addarray(1, 5, 9, 10);
	else if (total < 35)
	{
		if (total == 29)
			com = addarray(2, 6, 9, 10);
		else if ((total + 1) % 3 == 0)
			com = addnext(com, 2);
		else
			com = addnext(com, 1);
	}
	else
	{
		if (total == 35)
			com = addarray(1, 2, 3, 5);
		else if (total == 41)
			com = addarray(1, 2, 3, 7);
		else if ((total + 1) % 2 == 0)
			com = addnext(com, 3);
		else
			com = addnext(com, 1);
	}
	return (com);
}

static int		*nexttest_l(int *com, int total)
{
	if (total < 11)
	{
		if (total == 5)
			com = addarray(1, 2, 6, 10);
		else if ((total + 1) % 3 == 0)
			com = addnext(com, 2);
		else
			com = addnext(com, 1);
	}
	else if (total < 23)
	{
		if (total == 11)
			com = addarray(1, 5, 6, 7);
		else if (total == 17)
			com = addarray(3, 5, 6, 7);
		else if ((total + 1) % 2 == 0)
			com = addnext(com, 3);
		else
			com = addnext(com, 1);
	}
	else
		com = nexttest_lr(com, total);
	return (com);
}

int				check_lshape(int pos[4])
{
	int		total;
	int		count;
	int		*com;

	total = -1;
	com = (int *)malloc(sizeof(int) * 4);
	if (!com)
		return (0);
	com = addarray(1, 2, 5, 9);
	while (++total < 48)
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
		com = nexttest_l(com, total);
	}
	free(com);
	return (0);
}
