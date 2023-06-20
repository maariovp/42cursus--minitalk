/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:39:03 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 18:50:11 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			cont;
	unsigned char	*conv_s;
	unsigned char	*conv_t;

	conv_s = (unsigned char *)s1;
	conv_t = (unsigned char *)s2;
	cont = 0;
	if (n == 0)
		return (0);
	while (conv_s[cont] == conv_t[cont] && cont < (n - 1))
		cont++;
	return (conv_s[cont] - conv_t[cont]);
}
