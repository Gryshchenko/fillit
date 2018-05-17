/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:37:17 by vgryshch          #+#    #+#             */
/*   Updated: 2017/11/30 16:34:32 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int *n, int *negative)
{
	int		tmp;
	int		counter;

	tmp = *n;
	counter = 1;
	if (*n < 0)
	{
		*n = *n * -1;
		*negative = 1;
		counter++;
	}
	while (tmp /= 10)
		counter++;
	return (counter);
}

char		*ft_itoa(int n)
{
	int		len;
	int		negative;
	char	*newstr;

	negative = 0;
	len = ft_counter(&n, &negative);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(newstr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	newstr[len] = '\0';
	while (len--)
	{
		newstr[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		newstr[0] = '-';
	return (newstr);
}
