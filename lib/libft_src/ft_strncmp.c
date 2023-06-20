/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:35:51 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 17:31:21 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	cont;
	unsigned int	n_return;

	cont = 0;
	n_return = 0;
	while ((cont < n) && !n_return && (s1[cont] != '\0') && (s2[cont] != '\0'))
	{
		n_return = ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
		cont++;
	}
	if (cont < n && !n_return && (s1[cont] == '\0' || s2[cont] == '\0'))
	{
		n_return = ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
	}
	return (n_return);
}
