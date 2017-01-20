/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:59:59 by eliu              #+#    #+#             */
/*   Updated: 2016/12/10 00:40:15 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find(char **temp, char c, int temp_x)
{
	int		i;
	int		j;
	char	letter;

	i = -1;
	letter = ft_letter(temp);
	letter--;
	while (temp[++i])
	{
		j = -1;
		while (temp[i][++j])
		{
			if (temp[i][j] == letter)
			{
				if (c == 'y')
					return (i);
				if (temp_x > j)
					temp_x = j;
			}
		}
	}
	return (temp_x + 1);
}
