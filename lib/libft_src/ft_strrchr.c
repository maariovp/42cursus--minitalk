/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:52:47 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 18:00:03 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	cont;

	cont = ft_strlen(s);
	while (cont >= 0)
	{
		if (s[cont] == c)
			return (((char *)s + cont));
		cont--;
	}
	return (0);
}
