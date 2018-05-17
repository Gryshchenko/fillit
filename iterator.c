/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandrush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:17:01 by vandrush          #+#    #+#             */
/*   Updated: 2018/01/30 12:22:27 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			place_element(t_element *el, t_field *f, t_point *p)
{
	int		i;
	int		j;

	j = 0;
	while (j < 4)
	{
		i = (p->y + el->coords[j].y) * (f->len + 1) + p->x + el->coords[j].x;
		f->pool[i] = el->symbol;
		j++;
	}
}

int				can_be_placed(t_element *el, t_field *f, t_point *p)
{
	int		j;
	int		i;

	if (p->x < 0)
		return (0);
	j = 0;
	while (j < 4)
	{
		if ((p->x + el->coords[j].x >= f->len) ||
			(p->y + el->coords[j].y >= f->len))
			return (0);
		i = (p->y + el->coords[j].y) * (f->len + 1) + p->x + el->coords[j].x;
		if (f->pool[i] != '.')
			return (0);
		j++;
	}
	return (1);
}

static void		clear_element(t_element *el, t_field *f)
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = (el->position->y + el->coords[j].y) * (f->len + 1)
			+ el->position->x + el->coords[j].x;
		f->pool[i] = '.';
		j++;
	}
}

static int		try_place(t_element *el, t_field *f)
{
	if (!find_empty_point(f, el->position))
	{
		el->position->x = -1;
		el->position->y = 0;
		return (0);
	}
	while (!can_be_placed(el, f, el->position))
	{
		if (!find_empty_point(f, el->position))
		{
			el->position->x = -1;
			el->position->y = 0;
			return (0);
		}
	}
	place_element(el, f, el->position);
	return (1);
}

int				iterator(t_field *f, t_element **elements, int n, int deep)
{
	t_element	*el;

	el = *elements;
	if (try_place(el, f))
	{
		if (n == 1)
			return (0);
		return (iterator(f, elements + 1, n - 1, deep + 1));
	}
	else
	{
		if (deep > 0)
		{
			clear_element(elements[-1], f);
			return (iterator(f, elements - 1, n + 1, deep - 1));
		}
		else
			return (1);
	}
}
