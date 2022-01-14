/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:00:29 by wroyal            #+#    #+#             */
/*   Updated: 2021/05/05 17:24:32 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mas;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (s1[l] != '\0')
		l++;
	mas = malloc(sizeof(char) * l + 1);
	if (mas == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		mas[i] = s1[i];
		i++;
	}
	mas[i] = '\0';
	return (mas);
}
