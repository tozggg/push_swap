/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:31:07 by taejkim           #+#    #+#             */
/*   Updated: 2021/01/07 16:25:57 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	int				i;

	if (dst == src)
		return (dst);
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0 - 1;
	if (dst < src)
	{
		while ((unsigned)++i < n)
			ptr1[i] = ptr2[i];
	}
	else
	{
		while ((unsigned)++i < n)
			ptr1[(n - 1) - i] = ptr2[(n - 1) - i];
	}
	return (dst);
}
