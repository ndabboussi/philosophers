/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-06 14:45:31 by ndabbous          #+#    #+#             */
/*   Updated: 2025-06-06 14:45:31 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philos *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	ft_think(t_philos *philo)
{
	ft_print_msg(philo, "is thinking");
	if (philo->nb_philos % 2 != 0)
	{
		if (!((philo->time_eat * 2) < philo->time_sleep))
			ft_usleep(philo->time_eat);
	}
}

void	ft_sleep(t_philos *philo)
{
	ft_print_msg(philo, "is sleeping");
	ft_usleep(philo->time_sleep);
}

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!check_death(philo))
	{
		if (philo->meals_goal > 0 && philo->meals_eaten >= philo->meals_goal)
			break ;
		ft_eat(philo);
		if (check_death(philo))
			break ;
		ft_sleep(philo);
		if (check_death(philo))
			break ;
		ft_think(philo);
	}
	return (arg);
}
