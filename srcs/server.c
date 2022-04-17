/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:30:23 by lhelena           #+#    #+#             */
/*   Updated: 2022/04/17 14:22:34 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_y = 2;

static void	send_s1(int pid)
{
	usleep(SLEEP);
	if (kill(pid, S1) < 0)
		error_and_exit(ERR_005);
}

static void	print_c(char c, char *str)
{
	if (c == 0)
	{
		ft_printf("%s\n", str);
		g_y = 2;
	}
	else
	{
		str[ft_strlen(str) + 1] = '\0';
		str[ft_strlen(str)] = c;
		g_y = 1;
	}
}

static void	put_default(void *d, void *c)
{
	*(int *)d = BIT;
	*(int *)c = 0;
	g_y = 0;
}

static void	ft_saction(int signum, siginfo_t *siginfo, void *context)
{
	static char	c;
	static int	digit;
	static char	str[ARG_MAX + 1];

	(void)context;
	if (g_y == 2)
	{
		str[0] = '\0';
		g_y = 1;
	}
	if (g_y == 1)
		put_default(&digit, &c);
	if (signum == S0)
	{
		digit /= 2;
		send_s1(siginfo->si_pid);
	}
	else if (signum == S1)
	{
		c = c | digit;
		digit /= 2;
		send_s1(siginfo->si_pid);
	}
	if (digit == 0)
		print_c(c, str);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server's PID is: %d\n", getpid());
	sa.sa_sigaction = ft_saction;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(S0, &sa, NULL) < 0)
		error_and_exit(ERR_006);
	if (sigaction(S1, &sa, NULL) < 0)
		error_and_exit(ERR_006);
	while (1)
		pause();
	return (0);
}
