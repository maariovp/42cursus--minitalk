/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:43:22 by mavicent          #+#    #+#             */
/*   Updated: 2023/01/12 11:39:42 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_percentage(const char *str)
{
	if (*str != '%')
		return (0);
	str++;
	if (*str == 'c')
		return (1);
	if (*str == 's')
		return (2);
	if (*str == 'p')
		return (3);
	if (*str == 'd')
		return (4);
	if (*str == 'i')
		return (5);
	if (*str == 'u')
		return (6);
	if (*str == 'x')
		return (7);
	if (*str == 'X')
		return (8);
	if (*str == '%')
		return (9);
	return (0);
}

int	operation(int temp, va_list args)
{
	int	n_prints;

	n_prints = 0;
	if (temp == 1)
		n_prints += ft_putchar(va_arg(args, int));
	else if (temp == 2)
		n_prints += ft_putstr(va_arg(args, char *));
	else if (temp == 3)
		n_prints += ft_putpointer(va_arg(args, unsigned long long));
	else if (temp == 4)
		n_prints += ft_putnbr(va_arg(args, int));
	else if (temp == 5)
		n_prints += ft_putnbr(va_arg(args, int));
	else if (temp == 6)
		n_prints += ft_putusi(va_arg(args, int));
	else if (temp == 7)
		n_prints += ft_hexa(va_arg(args, unsigned int), 1);
	else if (temp == 8)
		n_prints += ft_hexa(va_arg(args, unsigned int), 0);
	else if (temp == 9)
		n_prints += ft_putchar(37);
	return (n_prints);
}

int	ft_printf(const char *fmt, ...)
{
	int		temp;
	int		n_prints;
	va_list	args;

	va_start(args, fmt);
	n_prints = 0;
	while (*fmt != '\0')
	{
		temp = check_percentage(fmt);
		if (temp == 0)
		{
			n_prints += ft_putchar(*fmt);
			fmt++;
		}
		else
		{
			n_prints += operation(temp, args);
			fmt += 2;
		}
	}
	va_end(args);
	return (n_prints);
}
