/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:44:19 by taejkim           #+#    #+#             */
/*   Updated: 2020/12/29 19:31:30 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	ptr_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	ptr_len = 0;
	i = 0;
	while (s[i])
	{
		if (i >= start && ptr_len < len)
			++ptr_len;
		++i;
	}
	ptr = (char *)malloc(sizeof(char) * (ptr_len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ptr_len)
	{
		ptr[i] = s[start + i];
		++i;
	}
	ptr[i] = 0;
	return (ptr);
}
