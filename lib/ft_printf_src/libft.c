/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:01:47 by mavicent          #+#    #+#             */
/*   Updated: 2023/01/12 11:19:42 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(const char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] != '\0')
		cont++;
	cont--;
	return (cont);
}

int	ft_putnbr(int nb)
{
	long	li;
	int		n_prints;

	li = nb;
	n_prints = 0;
	if (li < 0)
	{
		n_prints += ft_putchar('-');
		li = (-li);
	}
	if (li > 9)
	{
		n_prints += ft_putnbr(li / 10);
		n_prints += ft_putnbr(li % 10);
	}
	else
		n_prints = n_prints + ft_putchar(li + '0');
	return (n_prints);
}
