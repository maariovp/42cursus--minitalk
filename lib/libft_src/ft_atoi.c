/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:29:41 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/22 16:05:00 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	num_return;
	unsigned int	sinal;
	unsigned int	cont;

	cont = 0;
	sinal = 1;
	num_return = 0;
	while (nptr[cont] == 32 || (nptr[cont] >= 9 && nptr[cont] <= 13))
		cont++;
	if (nptr[cont] == '+' || nptr[cont] == '-')
	{
		if (nptr[cont] == '-')
			sinal = -1;
	cont++;
	}
	while (nptr[cont] >= '0' && nptr[cont] <= '9')
	{
		num_return = num_return * 10 + nptr[cont] - '0';
		cont++;
	}
	return (sinal * (int)num_return);
}
