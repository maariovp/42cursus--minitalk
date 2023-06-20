/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:51:33 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/16 10:57:02 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	cont;
	size_t	j;
	size_t	leng_src;
	size_t	leng_dest;

	if (size == 0)
		return (ft_strlen(src));
	leng_src = ft_strlen (src);
	leng_dest = ft_strlen (dst);
	j = leng_dest;
	cont = 0;
	if (size < leng_dest)
		return (leng_src + size);
	while (src[cont] != '\0' && j < (size - 1))
	{
		dst[j] = src[cont];
		j++;
		cont++;
	}
	dst[j] = '\0';
	return (leng_dest + leng_src);
}
