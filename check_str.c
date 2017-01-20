/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:34:14 by kyang             #+#    #+#             */
/*   Updated: 2016/12/10 16:24:49 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				valid_str_char(char c, int checker)
{
	if (checker == 1)
	{
		if (c == '\n')
			return (1);
	}
	if (c == '.' || c == '#')
		return (1);
	return (0);
}

int				valid_counter(int count, int checker)
{
	if (checker == 0)
	{
		if (count % 4 != 0)
			return (0);
	}
	else
	{
		if (count != 4)
			return (0);
	}
	return (1);
}

int				valid_str(char *str, int count, int other, int ncount)
{
	if (str[count - 1] != '\n')
	{
		if (!valid_counter(other, 0))
			return (-1);
		ncount++;
	}
	else
	{
		if (!valid_str_char(str[count + 1], 0))
			return (-1);
		if (!valid_counter(ncount, 1))
			return (-1);
		ncount = 0;
	}
	return (ncount);
}

int				check_str(char *str)
{
	int			count;
	int			ncount;
	int			other;

	count = -1;
	ncount = 0;
	other = 0;
	if (str == NULL || !valid_str_char(str[0], 0))
		return (0);
	while (str[++count] != '\0')
	{
		if (!valid_str_char(str[count], 1))
			return (0);
		else if (str[count] == '\n')
		{
			ncount = valid_str(str, count, other, ncount);
			if (ncount == -1)
				return (0);
		}
		else
			other++;
	}
	if (ncount != 4)
		return (0);
	return (1);
}
