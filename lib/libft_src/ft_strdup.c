/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:09:25 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 20:03:10 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	cont;
	char	*s2;

	s2 = malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (!s2)
		return (NULL);
	cont = 0;
	while (s[cont] != '\0')
	{
		s2[cont] = s[cont];
		cont++;
	}
	s2[cont] = '\0';
	return (s2);
}
