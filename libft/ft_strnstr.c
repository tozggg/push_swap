/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 10:11:09 by taejkim           #+#    #+#             */
/*   Updated: 2020/12/28 16:41:32 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	if (*little == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && (i < len))
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] && (big[i + j] == little[j]) && (i + j < len))
			{
				++j;
				if (little[j] == 0)
					return ((char *)&big[i]);
			}
		}
		++i;
	}
	return (0);
}
