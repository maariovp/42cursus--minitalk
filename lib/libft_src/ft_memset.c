/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:20:56 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 17:55:06 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			cont;
	unsigned char	*conv_str;

	cont = 0;
	conv_str = (unsigned char *)s;
	while (cont < n)
	{
		conv_str[cont] = c;
		cont++;
	}
	return (s);
}
