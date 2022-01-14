/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 12:14:35 by wroyal            #+#    #+#             */
/*   Updated: 2021/05/09 13:57:09 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*ptr;
	unsigned char	ctr;

	i = 0;
	ptr = (unsigned char *) s;
	ctr = (unsigned char) c;
	while (n > 0)
	{
		if (ptr[i] == ctr)
			return (&ptr[i]);
		i++;
		n--;
	}
	return (NULL);
}
