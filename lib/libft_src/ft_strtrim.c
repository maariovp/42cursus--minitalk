/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:56:33 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 20:04:21 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char c, const char *set)
{
	size_t	cont;

	cont = 0;
	while (set[cont])
	{
		if (set[cont] == c)
			return (1);
		cont++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	cont;
	size_t	beg;
	size_t	final;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	beg = 0;
	while (s1[beg] && ft_set(s1[beg], set))
		beg++;
	final = ft_strlen(s1);
	while (final > beg && ft_set(s1[final - 1], set))
		final--;
	str = (char *)malloc(sizeof(*s1) * (final - beg + 1));
	if (!str)
		return (NULL);
	cont = 0;
	while (beg < final)
		str[cont++] = s1 [beg++];
	str[cont] = 0;
	return (str);
}
