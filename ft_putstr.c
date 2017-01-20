/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 10:15:07 by kyang             #+#    #+#             */
/*   Updated: 2016/12/11 15:34:09 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char const *str)
{
	int count;

	count = 0;
	if (!str)
		return ;
	while (str[count])
	{
		ft_putchar(str[count]);
		count++;
	}
}
