/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:35:47 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 18:52:52 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	cont;

	cont = 0;
	while (s[cont] != c)
	{
		if (!s[cont])
			return (NULL);
		cont++;
	}
	return ((char *)s + cont);
}
