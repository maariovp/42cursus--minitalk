/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:41:52 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 18:53:23 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	cont;
	size_t	leng_src;

	cont = 0;
	leng_src = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size == 0)
		return (leng_src);
	while (src[cont] != '\0' && cont < (size - 1))
	{
		dst[cont] = src[cont];
		cont++;
	}
	dst[cont] = '\0';
	return (leng_src);
}
