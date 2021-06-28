/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:09:04 by taejkim           #+#    #+#             */
/*   Updated: 2021/01/07 16:59:52 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t res;
	size_t i;

	if (dst == NULL && src == NULL)
		return (0);
	res = ft_strlen(src);
	if (dstsize == 0)
		return (res);
	i = 0;
	while (i < (dstsize - 1))
	{
		if (src[i] == 0)
			break ;
		dst[i] = src[i];
		++i;
	}
	dst[i] = 0;
	return (res);
}
