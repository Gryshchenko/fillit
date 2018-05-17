/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:45:21 by vgryshch          #+#    #+#             */
/*   Updated: 2018/01/30 12:18:53 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	ft_tetri_validator(char *n)
{
	int	i;

	i = -1;
	if (n[0] == '\0' || n[0] == '\n')
		return (0);
	if (n[4] != '\n' || n[9] != '\n')
		return (0);
	else if (n[14] != '\n' || n[19] != '\n')
		return (0);
	else if ((n[20] != '\n' && n[20] != '\0'))
		return (0);
	while (++i < 20)
	{
		if (n[i] != '#' && n[i] != '.' && n[i] != '\n' && n[i] != '\0')
			return (0);
	}
	return (1);
}

static int	ft_tetri_countnumber(char *n)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (i < 20)
	{
		if (n[i] == '#')
			counter++;
		i++;
	}
	if (counter == 4)
		return (1);
	return (0);
}

static char	ft_tetri_dependencies(char *n)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i <= 20)
	{
		if (n[i] == '#')
		{
			if ((i + 1) < 20 && n[i + 1] == '#')
				counter++;
			if ((i - 1) >= 0 && n[i - 1] == '#')
				counter++;
			if ((i + 5) < 20 && n[i + 5] == '#')
				counter++;
			if ((i - 5) >= 0 && n[i - 5] == '#')
				counter++;
		}
		i++;
	}
	if (counter == 6 || counter == 8)
		return (1);
	return (0);
}

int			ft_read_file(int ret, char *buf)
{
	int	n;

	n = 0;
	if (ret < 546)
	{
		while (*buf != '\0')
		{
			if (ft_tetri_validator(buf) == 0 || ft_tetri_dependencies(buf) == 0
					|| ft_tetri_countnumber(buf) == 0
					|| (ft_strlen(buf) == 21 && buf[20] != '\0'))
				return (0);
			buf = buf + 21;
			n++;
		}
		return (n);
	}
	return (0);
}
