/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:17:39 by dkot              #+#    #+#             */
/*   Updated: 2024/12/24 15:32:38 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power_of_two(int n)
{
	int	result;

	result = 1;
	while (n > 0)
	{
		result = result * 2;
		n--;
	}
	return (result);
}

void	check_signals(int signal)
{
	static unsigned char	current_char;
	static int				bit_counter;
	static char				array[10000];
	static int				message_length;

	if (bit_counter < 8)
	{
		if (signal == SIGUSR2)
			current_char = current_char + power_of_two(bit_counter);
		bit_counter++;
	}
	if (bit_counter == 8)
	{
		array[message_length] = current_char;
		if (current_char == '\0')
		{
			ft_printf("%s\n", array);
			message_length = 0;
			ft_memset(array, 0, sizeof(array));
		}
		else
			message_length++;
		bit_counter = 0;
		current_char = 0;
	}
}

int	main(void)
{
	ft_printf("%d - PID\n", getpid());
	signal(SIGUSR1, check_signals);
	signal(SIGUSR2, check_signals);
	while (1)
		pause();
	return (0);
}
