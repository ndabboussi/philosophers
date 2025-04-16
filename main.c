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

	if (check_input(ac, av) < 0)
		return (1);
	init_diner(&diner, ac, av);
	return (0);
}
