/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:33:19 by lbarrene          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/18 20:33:28 by lbarrene         ###   ########.fr       */
=======
/*   Updated: 2022/10/11 11:15:33 by lbarrene         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (10 <= n)
		{
			ft_putnbr_fd((n / 10), fd);
		}
		ft_putchar_fd((n % 10 + 48), fd);
	}
}
