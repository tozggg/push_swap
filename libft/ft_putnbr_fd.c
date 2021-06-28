/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:07:31 by taejkim           #+#    #+#             */
/*   Updated: 2021/01/07 18:42:12 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nbr_loop(int n, int fd)
{
	if (n >= 10)
		nbr_loop(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n >= 0)
		nbr_loop(n, fd);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		write(fd, "-", 1);
		nbr_loop(-n, fd);
	}
}
