/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:29:02 by mavicent          #+#    #+#             */
/*   Updated: 2023/02/09 17:31:42 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	send_char(int pid, char char_txt)
{
	char	index;

	index = 0;
	while (index < 8)
	{
		if (char_txt & (1 << index))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		index++;
		usleep(200);
	}
}

void	send_mens(int pid, char *text)
{
	int	index;

	index = 0;
	while (text[index] != '\0')
		send_char(pid, (int)text[index++]);
	send_char(pid, 0);
}

int	get_pid(char *pid)
{
	int	index;

	index = 0;
	while (pid[index] != '\0')
	{
		if (ft_isdigit(pid[index]) == 0)
			return (-1);
		index++;
	}
	return (ft_atoi(pid));
}

void	signal_hand(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Your message has been sent successfully!\n");
}

int	main(int argc, char *argv[])
{
	int	pid;

	signal(SIGUSR1, &signal_hand);
	if (argc != 3)
	{
		ft_printf("Wrong input!\n");
		ft_printf("try: './client_bonus [PID] [MESSAGE]'\n");
		return (0);
	}
	pid = get_pid(argv[1]);
	if (pid == -1)
	{
		ft_printf("Wrong pid.\n");
		return (0);
	}
	send_mens(pid, argv[2]);
	return (0);
}
