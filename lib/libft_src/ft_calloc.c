/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:52:03 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 18:10:42 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			cont;
	char			*string;
	unsigned int	len;

	len = size * nmemb;
	string = malloc(len);
	if (string == NULL)
		return (NULL);
	cont = 0;
	while (len > 0)
	{
		string[cont] = 0;
		cont++;
		len--;
	}
	return ((void *)string);
}
