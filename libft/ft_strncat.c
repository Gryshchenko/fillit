/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:48:56 by vgryshch          #+#    #+#             */
/*   Updated: 2017/11/28 13:55:36 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destptr, const char *srcptr, size_t num)
{
	size_t	i;
	size_t	a;

	i = ft_strlen(destptr);
	a = 0;
	while (srcptr[a] != '\0' && num)
	{
		destptr[i] = srcptr[a];
		a++;
		i++;
		num--;
	}
	destptr[i] = '\0';
	return (destptr);
}
