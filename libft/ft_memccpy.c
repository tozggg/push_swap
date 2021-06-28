/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:01:04 by taejkim           #+#    #+#             */
/*   Updated: 2020/12/28 13:14:41 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr;
	int				flag;
	size_t			i;

	ptr = (unsigned char *)src;
	flag = 0;
	i = 0;
	while (ptr[i] && (i < n) && (flag == 0))
	{
		if (ptr[i] == (unsigned char)c)
			flag = 1;
		++i;
	}
	if (flag)
	{
		ft_memcpy(dst, src, i);
		return (dst + i);
	}
	else
	{
		ft_memcpy(dst, src, n);
		return (0);
	}
}
