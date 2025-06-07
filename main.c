/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 09:57:24 by ndabbous          #+#    #+#             */
/*   Updated: 2025-04-11 09:57:24 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int ac, char **av)
{
	t_symposium	diner;
	int			meals;

	if (check_input(ac, av) < 0)
		return (1);
	if (init_diner(&diner, av) < 0)
		return (1);
	meals = 0;
	if (ac == 6)
		meals = ft_atoi(av[5]);
	init_philos(&diner, diner.philos, av);
	if (init_philos_threads(&diner, diner.philos) < 0)
		return (1);
	ft_safe_exit(&diner, "");
	return (0);
}
