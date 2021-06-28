/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 07:36:14 by taejkim           #+#    #+#             */
/*   Updated: 2021/01/12 18:55:45 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	unsigned long long	res;
	int					pos;
	int					i;

	res = 0;
	pos = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
			|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		++i;
	if (nptr[i] == '-')
		pos *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		++i;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		res = (nptr[i] - '0') + (res * 10);
		if (res > 9223372036854775807 && (pos == 1))
			return (-1);
		if (res > 9223372036854775807 && (pos == -1))
			return (0);
		++i;
	}
	return (res * pos);
}
