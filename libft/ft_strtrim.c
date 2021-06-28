/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:13:06 by taejkim           #+#    #+#             */
/*   Updated: 2021/01/16 15:45:59 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start(char const *s1, char const *set)
{
	int res;
	int set_len;
	int i;

	set_len = ft_strlen(set);
	res = -1;
	while (s1[++res])
	{
		i = -1;
		while (++i < set_len)
		{
			if (s1[res] == set[i])
				break ;
		}
		if (i == set_len)
			break ;
	}
	return (res);
}

static int	get_end(char const *s1, char const *set)
{
	int res;
	int set_len;
	int i;

	set_len = ft_strlen(set);
	res = ft_strlen(s1);
	while (--res >= 0)
	{
		i = -1;
		while (++i < set_len)
		{
			if (s1[res] == set[i])
				break ;
		}
		if (i == set_len)
			break ;
	}
	return (res + 1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		end;
	int		i;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (end == 0)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = 0;
	return (ptr);
}
