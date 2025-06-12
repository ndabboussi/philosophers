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
	return (1);
}

int	check_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd(ERR_NB, 2), -1);
	while (av[i])
	{
		if (is_digits(av[i]) < 0)
			return (ft_putstr_fd(ERR_ARGS, 2), -1);
		i++;
	}
	if (ft_atoi(av[1]) > 250 || ft_atoi(av[1]) <= 0)
		return (ft_putstr_fd(ERR_NB_PHILO, 2), -1);
	if (ft_atoi(av[2]) <= 0 || ft_atoi(av[2]) > 2147483647 || !is_digits(av[2]))
		return (ft_putstr_fd(ERR_NB_DIE, 2), -1);
	if (ft_atoi(av[3]) <= 0 || ft_atoi(av[3]) > 2147483647 || !is_digits(av[3]))
		return (ft_putstr_fd(ERR_NB_EAT, 2), -1);
	if (ft_atoi(av[4]) <= 0 || ft_atoi(av[4]) > 2147483647 || !is_digits(av[4]))
		return (ft_putstr_fd(ERR_NB_SLEEP, 2), -1);
	if (ac == 6 && (ft_atoi(av[5]) <= 0 || ft_atoi(av[5]) > 2147483647 \
										|| !is_digits(av[5])))
		return (ft_putstr_fd(ERR_NB_MEALS, 2), -1);
	return (0);
}
