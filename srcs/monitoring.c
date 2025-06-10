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
	pthread_mutex_lock(&diner->stop_lock);
	while (i < diner->philos[0].nb_philos)
	{
		if (butler_death_check(&diner->philos[i]) || \
				(diner->count_full_philos != 0 && \
				diner->count_full_philos == diner->nb_philos))
		{
			pthread_mutex_lock(&diner->dead_lock);
			diner->dead = 1;
			pthread_mutex_unlock(&diner->dead_lock);
			pthread_mutex_lock(&diner->start_lock);
			if (diner->flag_start == 1 && (diner->count_full_philos == 0 && \
				diner->count_full_philos != diner->nb_philos))
				tragic_announcement(&diner->philos[i], "died");
			pthread_mutex_unlock(&diner->stop_lock);
			pthread_mutex_unlock(&diner->start_lock);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&diner->stop_lock);
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
