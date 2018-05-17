/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:23:37 by vgryshch          #+#    #+#             */
/*   Updated: 2017/12/04 16:37:34 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *string1, const char *string2)
{
	int i;

	i = 0;
	while (string1[i] != '\0' && string2[i] != '\0' && string1[i] == string2[i])
		i++;
	return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}
