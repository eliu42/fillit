/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 20:45:19 by kyang             #+#    #+#             */
/*   Updated: 2016/12/11 15:36:09 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t		count;
	size_t		len;

	count = 0;
	len = ft_strlen(s1);
	while (count != n && s2[count] != '\0')
	{
		s1[len + count] = s2[count];
		count++;
	}
	s1[len + count] = '\0';
	return (s1);
}
