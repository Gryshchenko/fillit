/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:17:01 by vgryshch          #+#    #+#             */
/*   Updated: 2017/12/03 18:18:56 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;
	char	*big1;
	char	*little2;

	i = 0;
	big1 = (char *)big;
	little2 = (char *)little;
	if (little[0] == '\0')
		return ((char *)big);
	n = ft_strlen(little2);
	while (big1[i] != '\0' && (i + n) <= len)
	{
		if (ft_strncmp(big + i, little, n) == 0)
			return (big1 + i);
		i++;
	}
	return (NULL);
}
