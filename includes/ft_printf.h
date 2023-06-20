/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:10:28 by mavicent          #+#    #+#             */
/*   Updated: 2023/02/09 17:04:49 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_putchar(const char c);

int		ft_strlen(const char *str);

int		ft_putnbr(int nb);

int		ft_putstr(const char *str);

int		ft_putpointer(unsigned long long poin);

int		ft_putusi(unsigned int nb);

int		ft_putstr_inv(const char *str);

int		ft_hexa(unsigned long long nbr, int ope);

int		ft_printf(const char *fmt, ...);

#endif