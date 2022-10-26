/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:10:26 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/30 14:17:24 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	while (0 <= a)
	{
		if (str[a] == (char)c)
			return ((char *)str + a);
		a--;
	}
	return (NULL);
}
