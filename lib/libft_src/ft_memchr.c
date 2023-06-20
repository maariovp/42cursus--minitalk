/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:04:49 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 18:46:44 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cont;
	unsigned char	*conv_s;

	cont = 0;
	conv_s = (unsigned char *)s;
	while (cont < n)
	{
		if (conv_s[cont] == (unsigned char)c)
			return (conv_s + cont);
		cont++;
	}
	return (NULL);
}
