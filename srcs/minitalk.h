/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:06:11 by lhelena           #+#    #+#             */
/*   Updated: 2022/04/17 18:07:34 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define ERR_001 "First argument must be correct Pid number."
# define ERR_004 "Wrong arguments. Usage: ./client server-pid message"
# define ERR_005 "Kill isn't sent."
# define ERR_006 "Sigaction problem."
# define BIT 64
# define SLEEP 300
# define S0 SIGUSR1
# define S1 SIGUSR2

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>

void	error_and_exit(char *message);

#endif
