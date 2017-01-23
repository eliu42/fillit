/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 23:01:04 by kyang             #+#    #+#             */
/*   Updated: 2016/12/11 15:34:24 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	temp;
	size_t			count;
	char			*str;

	temp = (unsigned char)c;
	str = (char *)b;
	count = 0;
	while (count < len)
	{
		str[count] = temp;
		count++;
	}
	return (str);
}
