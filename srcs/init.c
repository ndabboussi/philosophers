/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 10:29:32 by ndabbous          #+#    #+#             */
/*   Updated: 2025-04-11 10:29:32 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos_threads(t_symposium *diner, t_philos *philos)
{
	pthread_t	butler;
	int			i;

	i = 0;
	if (pthread_create(&butler, NULL, &monitoring, diner) != 0)
		return (ft_safe_exit(diner, ERR_CREATE_THREAD), -1);
	while (i < diner->nb_philos)
	{
		if (pthread_create(&diner->philos[i].thread, \
								NULL, &routine, &diner->philos[i]) != 0)
			return (ft_safe_exit(diner, ERR_CREATE_THREAD), -1);
		i++;
	}
	i = 0;
	if (pthread_join(butler, NULL) != 0)
		return (ft_safe_exit(diner, ERR_JOIN_THREAD), -1);
	while (i < diner->nb_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (ft_safe_exit(diner, ERR_JOIN_THREAD), -1);
		i++;
	}
	return (0);
}

void	init_philos_2(t_philos *philo, char **av, int i)
{
	philo[i].id = i + 1;
	philo[i].meals_eaten = 0;
	philo[i].eating = 0;
	philo[i].sleeping = 0;
	philo[i].nb_philos = ft_atoi(av[1]);
	philo[i].time_die = ft_atoi(av[2]);
	philo[i].time_eat = ft_atoi(av[3]);
	philo[i].time_sleep = ft_atoi(av[4]);
	if (av[5])
		philo[i].meals_goal = ft_atoi(av[5]);
}

void	init_philos(t_symposium *diner, t_philos *philo, char **av)
{
	int	i;

	i = 0;
	while (i < diner->nb_philos)
	{
		init_philos_2(philo, av, i);
		philo[i].dead = &diner->dead;
		philo[i].full = &diner->count_full_philos;
		philo[i].start_time = ft_get_time();
		philo[i].last_meal_time = ft_get_time();
		philo[i].exit_routine_lock = &diner->stop_lock;
		philo[i].write_lock = &diner->write_lock;
		philo[i].dead_lock = &diner->dead_lock;
		philo[i].meal_lock = &diner->meal_lock;
		philo[i].l_fork = &diner->forks[i];
		if (i == 0)
			philo[i].r_fork = &diner->forks[diner->nb_philos - 1];
		else
			philo[i].r_fork = &diner->forks[i - 1];
		i++;
	}
}

int	init_forks(t_symposium *diner)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), \
			diner->nb_philos);
	if (!forks)
		return (ft_putstr_fd(ERR_ALLOC, 2), -1);
	while (i < diner->nb_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	diner->forks = forks;
	return (0);
}

int	init_diner(t_symposium *diner, char **av)
{
	int			i;
	t_philos	*philos;

	i = 0;
	diner->dead = 0;
	diner->count_full_philos = 0;
	diner->start_time = ft_get_time();
	diner->nb_philos = ft_atoi(av[1]);
	diner->time_die = ft_atoi(av[2]);
	diner->time_eat = ft_atoi(av[3]);
	diner->time_sleep = ft_atoi(av[4]);
	if (av[5])
		diner->meals_goal = ft_atoi(av[5]);
	philos = (t_philos *)ft_calloc(sizeof(t_philos), diner->nb_philos);
	if (!philos)
		return (ft_putstr_fd(ERR_ALLOC, 2), -1);
	diner->philos = philos;
	pthread_mutex_init(&diner->stop_lock, NULL);
	pthread_mutex_init(&diner->dead_lock, NULL);
	pthread_mutex_init(&diner->meal_lock, NULL);
	pthread_mutex_init(&diner->write_lock, NULL);
	if (init_forks(diner) < 0)
		return (-1);
	return (0);
}
