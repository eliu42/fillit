/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 21:03:49 by kyang             #+#    #+#             */
/*   Updated: 2016/12/11 15:35:10 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putendl(char const *s)
{
	if (!s)
		return ;
	ft_putstr(s);
	ft_putchar('\n');
}