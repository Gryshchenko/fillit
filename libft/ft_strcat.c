/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:08:18 by vgryshch          #+#    #+#             */
/*   Updated: 2017/11/23 11:19:00 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destptr, const char *srcptr)
{
	int i;
	int a;

	a = 0;
	i = ft_strlen(destptr);
	while (srcptr[a] != '\0')
	{
		destptr[i + a] = srcptr[a];
		a++;
	}
	destptr[i + a] = '\0';
	return (destptr);
}
