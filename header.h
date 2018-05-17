/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:36:26 by vgryshch          #+#    #+#             */
/*   Updated: 2018/01/30 15:00:18 by vandrush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 4096

typedef unsigned char	t_byte;

typedef struct	s_point
{
	char		x;
	char		y;
}				t_point;

typedef struct	s_element
{
	t_point		*position;
	t_point		coords[4];
	char		symbol;
}				t_element;

typedef	struct	s_field
{
	int			len;
	char		*pool;
}				t_field;

int				ft_read_file(int ret, char *buf);
void			ft_validation_error(void);
void			ft_tetra_loader(char *n, t_element **elements);
int				combo(t_element **arr, int n, t_field **min_field, int els);
void			fill_field(t_field **f, t_element **elements, int n);
t_field			*create_field(int len);
int				get_min_square(int n);
int				iterator(t_field *f, t_element **elements, int n, int deep);
t_point			*create_point(char x, char y);
t_point			*find_empty_point(t_field *f, t_point *p);
int				can_be_placed(t_element *el, t_field *f, t_point *p);
void			place_element(t_element *el, t_field *f, t_point *p);
void			extend_field(t_field **f);
#endif
