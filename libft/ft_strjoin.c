/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:58:15 by taejkim           #+#    #+#             */
/*   Updated: 2021/01/14 21:49:53 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
		return ((s1 != NULL) ? ft_strdup(s1) : ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		ptr[i++] = s1[j];
	j = -1;
	while (s2[++j])
		ptr[i++] = s2[j];
	ptr[i] = 0;
	return (ptr);
}
