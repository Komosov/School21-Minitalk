/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:33:15 by lhelena           #+#    #+#             */
/*   Updated: 2022/04/17 14:35:05 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_and_exit(char *message)
{
	ft_putchar_fd('\n', 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\nError\n", 2);
	exit(EXIT_FAILURE);
}
