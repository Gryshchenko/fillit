/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:09:18 by vgryshch          #+#    #+#             */
/*   Updated: 2018/01/30 15:00:06 by vandrush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_field	*create_field(int len)
{
	char	*pool;
	int		i;
	t_field	*field;

	if (!(pool = (char*)malloc(sizeof(char) * len * (len + 1) + 1)))
		return (NULL);
	i = 0;
	while (i < (len * (len + 1)))
	{
		pool[i] = '.';
		if ((i + 1) % (len + 1) == 0)
			pool[i] = '\n';
		i++;
	}
	pool[i] = '\0';
	if (!(field = (t_field*)malloc(sizeof(t_field))))
		return (NULL);
	field->len = len;
	field->pool = pool;
	return (field);
}

int		get_min_square(int n)
{
	int square;
	int solution;

	square = n * 4;
	solution = square / 2;
	while (solution * solution >= square)
		solution--;
	return (solution + 1);
}

void	extend_field(t_field **f)
{
	t_field	*new_f;

	new_f = create_field((*f)->len + 1);
	free((*f)->pool);
	free(*f);
	*f = new_f;
}

t_point	*find_empty_point(t_field *f, t_point *p)
{
	int		i;

	if (p->x + 1 == f->len)
	{
		if (p->y == f->len - 1)
			return (NULL);
		(p->y)++;
	}
	p->x = (p->x + 1) % f->len;
	i = p->y * (f->len + 1) + p->x;
	while (f->pool[i] != '.' && f->pool[i] != '\0')
		i++;
	if (f->pool[i] == '\0')
		return (NULL);
	p->x = i % (f->len + 1);
	p->y = i / (f->len + 1);
	return (p);
}

t_point	*find_and_extend(t_field **f, t_point *p)
{
	while (!find_empty_point(*f, p))
	{
		extend_field(f);
		p->x = -1;
		p->y = 0;
	}
	return (p);
}
