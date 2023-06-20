/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:23:59 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 18:44:39 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			cont;
	unsigned char	*conv_src;
	unsigned char	*conv_dest;

	cont = 0;
	if (!dest && !src)
		return (NULL);
	conv_src = (unsigned char *)src;
	conv_dest = (unsigned char *)dest;
	while (cont < n)
	{
		*(conv_dest + cont) = *(conv_src + cont);
		cont++;
	}
	return (dest);
}
