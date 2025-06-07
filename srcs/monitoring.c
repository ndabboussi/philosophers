/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-07 15:23:42 by ndabbous          #+#    #+#             */
/*   Updated: 2025-06-07 15:23:42 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	butler_death_check(t_philos	*philo)
{
	size_t	check_time;
	int		difference;

	pthread_mutex_lock(philo->meal_lock);
	check_time = ft_get_time();
	difference = check_time - philo->last_meal_time;
	if (difference >= philo->time_die)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	is_anyone_dead(t_symposium *diner)
{
	int	i;

	i = 0;
	while (i < diner->philos[0].nb_philos)
	{
		if (butler_death_check(&diner->philos[i]))
		{
			pthread_mutex_lock(&diner->dead_lock);
			diner->dead = 1;
			pthread_mutex_unlock(&diner->dead_lock);
			// pthread_mutex_lock(diner->philos[i].dead_lock);
			// *diner->philos[i].dead = 1;
			// pthread_mutex_unlock(diner->philos[i].dead_lock);
			tragic_announcement(&diner->philos[i], "died");
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_symposium	*diner;

	diner = (t_symposium *)arg;
	while (1)
	{
		if (is_anyone_dead(diner) == 1)
			return (arg);
	}
	return (arg);
}
