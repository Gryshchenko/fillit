/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:19:09 by vgryshch          #+#    #+#             */
/*   Updated: 2017/11/30 10:34:55 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_words_counter(const char *s, char c)
{
	size_t	counter;
	size_t	w_counter;

	counter = 0;
	w_counter = 0;
	while (s[counter])
	{
		while (s[counter] == c && s[counter])
			counter++;
		if (s[counter])
			w_counter++;
		while (s[counter] != c && s[counter])
			counter++;
	}
	return (w_counter);
}

static int		ft_char_count(const char *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s != c && *s)
	{
		s++;
		counter++;
	}
	return (counter);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	len;
	size_t	fr;
	size_t	sd;

	if (!s)
		return (NULL);
	fr = 0;
	len = ft_words_counter(s, c);
	if (!(str = (char **)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (*s && fr < len)
	{
		sd = 0;
		while (*s == c && *s)
			s++;
		if (!(str[fr] = (char *)malloc(sizeof(char) * ft_char_count(s, c) + 1)))
			return (NULL);
		while (*s != c && *s)
			str[fr][sd++] = *s++;
		str[fr][sd] = '\0';
		fr++;
	}
	str[fr] = NULL;
	return (str);
}
