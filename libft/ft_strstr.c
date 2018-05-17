/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:01:16 by vgryshch          #+#    #+#             */
/*   Updated: 2017/11/23 12:59:22 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int a;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (ft_strlen(big) >= ft_strlen(little))
	{
		while (big[i] != '\0')
		{
			a = 0;
			while (big[i + a] == little[a])
			{
				a++;
				if (little[a] == '\0')
					return ((char *)big + i);
			}
			i++;
		}
	}
	return (0);
}
