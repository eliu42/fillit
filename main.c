/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 22:19:45 by kyang             #+#    #+#             */
/*   Updated: 2016/12/10 00:38:14 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int arc, char **arg)
{
	int		error;
	char	***start;
	int		t[5];

	TY = 0;
	TX = 0;
	t[2] = -1;
	start = (char***)malloc(sizeof(char**) * 27);
	if (arc != 2)
	{
		ft_putstr("Usage: .\\fillit source_file\n");
		return (0);
	}
	error = fillit(arg[1], 0, start, t);
	if (error == -1)
		ft_putendl("error");
	return (0);
}
