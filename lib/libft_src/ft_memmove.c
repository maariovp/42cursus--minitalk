/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:22:52 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 19:08:57 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	if (!str1 && !str2)
		return (NULL);
	if (str2 < str1)
	{
		while (n != 0)
		{
			n--;
			((char *)str1)[n] = ((char *)str2)[n];
		}
	}
	else if (str2 > str1)
		ft_memcpy (str1, str2, n);
	return (str1);
}
