/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:29:18 by lbarrene          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/29 23:32:10 by lbarrene         ###   ########.fr       */
=======
/*   Updated: 2022/09/14 22:20:33 by lbarrene         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	a;
	char	*str;

<<<<<<< HEAD
	str = (char *)malloc(sizeof(*s1) * ((size_t)s1 + (size_t)s2 + 1));
=======
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
>>>>>>> refs/remotes/origin/main
	if (!str)
		return (NULL);
	i = 0;
	a = 0;
	while (s1[i])
		str[a++] = s1[i++];
	i = 0;
	while (s2[i])
		str[a++] = s2[i++];
	str[a] = '\0';
	return (str);
}
