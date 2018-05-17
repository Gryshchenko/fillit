/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:04:41 by vgryshch          #+#    #+#             */
/*   Updated: 2017/11/30 17:04:43 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_counter_int(int n)
{
	int		counter;
	int		tmp;

	counter = 1;
	tmp = n;
	if (!n)
		return (0);
	if (n < 0)
		counter++;
	while (tmp /= 10)
		counter++;
	return (counter);
}
