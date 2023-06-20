/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:56:35 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 20:02:53 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	flag;

	words = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			words++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (words);
}

static int	count_letters(char const *s, char c, int cont)
{
	int	size;

	size = 0;
	while (s[cont] != c && s[cont])
	{
		size++;
		cont++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		cont;
	int		j;
	int		words;
	char	**str;

	if (!s)
		return (NULL);
	cont = 0;
	j = -1;
	words = count_words(s, c);
	str = (char **)malloc((words + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < words)
	{
		while (s[cont] == c)
			cont++;
		str[j] = ft_substr(s, cont, count_letters(s, c, cont));
		if (!str)
			return (NULL);
		cont += count_letters(s, c, cont);
	}
	str[j] = 0;
	return (str);
}
