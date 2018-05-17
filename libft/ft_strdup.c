/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:06:21 by vgryshch          #+#    #+#             */
/*   Updated: 2017/11/24 17:00:48 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	if (!(dup = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
