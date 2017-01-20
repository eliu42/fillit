/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:43:54 by kyang             #+#    #+#             */
/*   Updated: 2016/12/11 15:35:56 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t		count;
	char		*str;

	count = 0;
	str = s1;
	while (*str)
		str++;
	while (s2[count] != '\0')
	{
		str[count] = s2[count];
		count++;
	}
	str[count] = '\0';
	return (s1);
}
