/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:30:27 by lhelena           #+#    #+#             */
/*   Updated: 2022/04/17 17:47:18 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_x = 1;

static void	ft_caction(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo->si_pid;
	if (signum == S1)
		g_x += 1;
}

static void	send_symbol(int pid, char c)
{
	int	digit;

	digit = BIT;
	while (digit > 0)
	{
		if (c & digit)
		{
			while (g_x != 1)
				pause();
			usleep(SLEEP);
			if (kill(pid, S1) < 0)
				error_and_exit(ERR_005);
			g_x = 0;
		}
		else
		{
			while (g_x != 1)
				pause();
			usleep(SLEEP);
			if (kill(pid, S0) < 0)
				error_and_exit(ERR_005);
			g_x = 0;
		}
		digit /= 2;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	if (argc != 3)
		error_and_exit(ERR_004);
	sa.sa_sigaction = ft_caction;
	sa.sa_flags = SA_SIGINFO;
	sigaction(S0, &sa, NULL);
	sigaction(S1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		error_and_exit(ERR_001);
	i = 0;
	while (argv[2][i])
	{
		send_symbol(pid, argv[2][i]);
		i++;
	}
	send_symbol(pid, '\0');
	while (g_x != 1)
		pause();
	ft_printf("The message has been successfully sent.\n");
	return (0);
}
