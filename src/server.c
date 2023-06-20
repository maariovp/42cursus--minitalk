/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:22:39 by mavicent          #+#    #+#             */
/*   Updated: 2023/02/09 17:18:56 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_hand(int signal)
{
	static int	value = 0;
	static char	index = 0;

	if (index == 7)
	{
		ft_printf("%c", value);
		value = 0;
		index = 0;
		return ;
	}
	if (signal == SIGUSR1)
		value = value | (0x1 << index);
	index++;
}

int	main(int argc, char *argv[])
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Wrong input!\n");
		ft_printf("Try: './server'\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID: %i\n", pid);
	while (1)
	{
		signal(SIGUSR1, &signal_hand);
		signal(SIGUSR2, &signal_hand);
	}
	return (0);
}
