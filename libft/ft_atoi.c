/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:38:26 by wroyal            #+#    #+#             */
/*   Updated: 2021/05/04 18:01:37 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_first(const	char *str)
{
	while (*str != '\0')
	{
		if (*str == '\t' || *str == '\n' || *str == '\v')
			str++;
		if (*str == '\r' || *str == ' ' || *str == '\f')
			str++;
		else
			str++;
	}
	return (*str);
}

int	ft_shield(long i, long a)
{
	if (i % 2 == 1)
		a *= -1;
	if (a < -2147483648)
		return (-1);
	if (a > 2147483647)
		return (0);
	return (a);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	a;

	i = 0;
	a = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		||*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		a = a + (*str - '0');
		a = a * 10;
		str++;
	}
	a = a / 10;
	return (ft_shield(i, a));
}
