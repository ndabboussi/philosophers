/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-07 15:29:24 by ndabbous          #+#    #+#             */
/*   Updated: 2025-06-07 15:29:24 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_drop_forks(t_philos *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}

void	ft_pick_forks(t_philos *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		ft_print_msg(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		ft_print_msg(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		ft_print_msg(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		ft_print_msg(philo, "has taken a fork");
	}
}

void	ft_eat(t_philos *philo)
{
	if (philo->nb_philos == 1)
	{
		pthread_mutex_lock(philo->r_fork);
		ft_print_msg(philo, "has taken a fork");
		ft_usleep(philo->time_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	ft_pick_forks(philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = ft_get_time();
	ft_print_msg(philo, "is eating");
	philo->eating = 1;
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_eat);
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
	ft_drop_forks(philo);
}
