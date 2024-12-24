/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:46:21 by dkot              #+#    #+#             */
/*   Updated: 2024/12/24 15:13:07 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_null(int pid)
{
	int	j;

	j = 8;
	while (j--)
	{
		kill(pid, SIGUSR1);
		usleep(400);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		i;
	int		j;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		j = 0;
		while (j++ < 8)
		{
			if ((argv[2][i] % 2) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(400);
			argv[2][i] = argv[2][i] / 2;
		}
		i++;
	}
	send_null(pid);
	return (0);
}
