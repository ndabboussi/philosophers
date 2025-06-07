/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-07 15:32:27 by ndabbous          #+#    #+#             */
/*   Updated: 2025-06-07 15:32:27 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	tragic_announcement(t_philos *philo, char *msg)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = ft_get_time() - philo->start_time;
	printf("%zu %i %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->write_lock);
}

void	ft_print_msg(t_philos *philo, char *msg)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = ft_get_time() - philo->start_time;
	if (!check_death(philo))
		printf("%zu %i %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->write_lock);
}

void	ft_safe_exit(t_symposium *diner, char *str)
{
	int	i;

	i = 0;
	if (str)
		ft_putstr_fd(str, 2);
	if (diner->forks)
	{
		while (i < diner->nb_philos)
		{
			pthread_mutex_destroy(&diner->forks[i]);
			i++;
		}
		free(diner->forks);
	}
	pthread_mutex_destroy(&diner->dead_lock);
	pthread_mutex_destroy(&diner->meal_lock);
	pthread_mutex_destroy(&diner->write_lock);
	if (diner->philos)
		free(diner->philos);
}
