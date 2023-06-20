/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:32:23 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 17:48:22 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			cont;
	unsigned char	*string;

	string = (unsigned char *)s;
	cont = 0;
	while (cont < n)
	{
		*(string + cont) = '\0';
		cont++;
	}
}
