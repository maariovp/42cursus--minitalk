/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:54:33 by mavicent          #+#    #+#             */
/*   Updated: 2023/01/12 11:33:26 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	index;
	int	n_prints;

	index = 0;
	n_prints = 0;
	if (!str)
		n_prints += ft_putstr("(null)");
	else
		while (str[index] != '\0')
			n_prints += ft_putchar(str[index++]);
	return (n_prints);
}

int	ft_putpointer(unsigned long long poin)
{
	int	n_prints;

	n_prints = 0;
	if (poin == 0)
		n_prints += ft_putstr("(nil)");
	else
	{
		n_prints += ft_putstr("0x");
		n_prints += ft_hexa(poin, 1);
	}
	return (n_prints);
}

int	ft_putusi(unsigned int nb)
{
	unsigned int	li;
	int				n_prints;

	li = nb;
	n_prints = 0;
	if (li > 9)
	{
		n_prints += ft_putusi(li / 10);
		n_prints += ft_putusi(li % 10);
	}
	else
		n_prints += ft_putchar(li + '0');
	return (n_prints);
}

int	ft_putstr_inv(const char *str)
{
	int	index;
	int	n_prints;

	index = ft_strlen(str);
	n_prints = 0;
	if (!str)
		return (0);
	while (index >= 0)
		n_prints += ft_putchar(str[index--]);
	return (n_prints);
}

int	ft_hexa(unsigned long long nbr, int ope)
{
	unsigned long long	resul;
	int					index;
	int					v_temp;
	char				v_hexa[100];

	index = 0;
	v_temp = 0;
	resul = nbr;
	while (resul != 0)
	{
		v_temp = resul % 16;
		if (v_temp >= 10 && ope == 0)
			v_temp += 55;
		if (v_temp >= 10 && ope == 1)
			v_temp += 87;
		if (v_temp < 10)
			v_temp += 48;
		v_hexa[index++] = v_temp;
		resul /= 16;
	}
	v_hexa[index++] = '\0';
	if (!nbr)
		return (ft_putchar('0'));
	return (ft_putstr_inv(v_hexa));
}
