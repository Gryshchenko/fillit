/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:45:21 by vgryshch          #+#    #+#             */
/*   Updated: 2018/01/30 15:13:07 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_validation_error(void)
{
	ft_putendl("error");
}

void	ft_read_argv(char *argv, char **temp, int *n)
{
	int		fd;
	int		ret;
	char	*buf;

	buf = ft_memalloc(BUF_SIZE);
	*temp = ft_memalloc(BUF_SIZE);
	fd = open(argv, O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	*temp = ft_strcpy(*temp, buf);
	*n = ft_read_file(ret, buf);
}

int		main(int argc, char **argv)
{
	char		*temp;
	int			n;
	t_field		*field;
	t_element	**elements;

	field = (void*)0;
	if (argc == 2)
	{
		ft_read_argv(argv[1], &temp, &n);
		if (n)
		{
			elements = (t_element**)malloc(sizeof(t_element*) * n);
			ft_tetra_loader(temp, elements);
			field = create_field(get_min_square(n));
			while (iterator(field, elements, n, 0))
				extend_field(&field);
			ft_putstr(field->pool);
		}
		else
			ft_validation_error();
	}
	if (argc != 2)
		ft_putendl("usage: ./fillit target_file");
	return (0);
}
