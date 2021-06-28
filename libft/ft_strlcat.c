/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:58:50 by taejkim           #+#    #+#             */
/*   Updated: 2021/01/14 20:32:50 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t d_len;
	size_t s_len;
	size_t i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize <= d_len)
		return (dstsize + s_len);
	else
	{
		i = 0;
		while (src[i] && ((d_len + i + 1) < dstsize))
		{
			dst[d_len + i] = src[i];
			++i;
		}
		dst[d_len + i] = 0;
		return (d_len + s_len);
	}
}
