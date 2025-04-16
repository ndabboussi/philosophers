/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 10:09:12 by ndabbous          #+#    #+#             */
/*   Updated: 2025-04-11 10:09:12 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	check_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		perror(RED "Error : wrong nb of args" RESET);
		return (-1);
	}
	while (av[i])
	{
		if (is_digits(av[i]) < 0)
		{
			perror(RED "Error : invalid arg" RESET);
			return (-1);
		}
		i++;
	}
	return (0);
}
