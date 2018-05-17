/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:28:45 by vgryshch          #+#    #+#             */
/*   Updated: 2018/01/30 12:58:33 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		move_to_corner(t_element *el)
{
	int		i;
	char	starting_x;
	char	starting_y;

	starting_x = (el->coords[0]).x;
	starting_y = (el->coords[0]).y;
	i = 0;
	while (i < 4)
	{
		el->coords[i].x -= starting_x;
		el->coords[i].y -= starting_y;
		i++;
	}
}

t_point			*create_point(char x, char y)
{
	t_point	*p;

	p = (t_point*)malloc(sizeof(t_point));
	if (!p)
		return (NULL);
	p->x = x;
	p->y = y;
	return (p);
}

static char		*ft_change_symbol(char *n, char *b, char symbol, t_element *el)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < 21)
	{
		b[i] = n[i];
		if (n[i] == '#')
		{
			(el->coords[j]).x = (i % 5);
			(el->coords[j]).y = (i / 5);
			j++;
			b[i] = symbol;
		}
	}
	move_to_corner(el);
	el->symbol = symbol;
	return (b);
}

void			ft_tetra_loader(char *n, t_element **elements)
{
	char		*loaded_str;
	char		symbol;
	t_element	*el;

	symbol = 'A';
	while (*n != '\0')
	{
		if (!(loaded_str = (char *)malloc(sizeof(char) * 21)))
		{
			ft_validation_error();
			return ;
		}
		ft_bzero(loaded_str, 22);
		el = (t_element*)malloc(sizeof(t_element));
		loaded_str = ft_change_symbol(n, loaded_str, symbol, el);
		el->position = create_point(-1, 0);
		symbol = symbol + 1;
		n = n + 21;
		*elements = el;
		elements++;
	}
}
