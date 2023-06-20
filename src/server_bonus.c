/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:40:55 by mavicent          #+#    #+#             */
/*   Updated: 2023/02/09 17:30:25 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	signal_hand(int signal, siginfo_t *info, void *context)
{
	static int	value = 0;
	static char	index = 0;

	(void)context;
	if (signal == SIGUSR1)
		value = value | (0x01 << index);
	if (index == 7)
	{
		if (value == 0)
			kill(info->si_pid, SIGUSR1);
		ft_printf("%c", value);
		value = 0;
		index = 0;
		return ;
	}
	index++;
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Wrong input!\n");
		ft_printf("Try: './server_bonus'\n");
		return (0);
	}
	pid = getpid();
	ft_printf("pid: %i\n", pid);
	sa.sa_sigaction = &signal_hand;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
	}
	return (0);
}
