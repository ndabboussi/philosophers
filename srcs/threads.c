/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-10 16:22:30 by ndabbous          #+#    #+#             */
/*   Updated: 2025-06-10 16:22:30 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_join(t_symposium *diner, t_philos *philos, pthread_t	butler, int i)
{
	int	j;

	j = 0;
	if (pthread_join(butler, NULL) != 0)
		return (ft_safe_exit(diner, ERR_JOIN_THREAD), -1);
	while (j < i)
	{
		if (pthread_join(philos[j].thread, NULL) != 0)
			return (ft_safe_exit(diner, ERR_JOIN_THREAD), -1);
		j++;
	}
	return (0);
}

int	init_philos_threads(t_symposium *diner, t_philos *philos)
{
	pthread_t	butler;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (pthread_create(&butler, NULL, &monitoring, diner) != 0)
		return (ft_safe_exit(diner, ERR_CREATE_THREAD), -1);
	pthread_mutex_lock(&diner->start_lock);
	while (i < diner->nb_philos)
	{
		if (pthread_create(&diner->philos[i].thread, \
								NULL, &routine, &diner->philos[i]) != 0)
		{
			diner->flag_start = -1;
			pthread_mutex_unlock(&diner->start_lock);
			ft_join(diner, philos, butler, i);
			return (ft_safe_exit(diner, ERR_CREATE_THREAD), -1);
		}
		i++;
	}
	diner->flag_start = 1;
	pthread_mutex_unlock(&diner->start_lock);
	ft_join(diner, philos, butler, i);
	return (0);
}

// int	init_philos_threads(t_symposium *diner, t_philos *philos)
// {
// 	pthread_t	butler;
// 	int			i;
// 	int			j;

// 	i = 0;
// 	j = 0;
// 	if (pthread_create(&butler, NULL, &monitoring, diner) != 0)
// 		return (ft_safe_exit(diner, ERR_CREATE_THREAD), -1);
// 	pthread_mutex_lock(&diner->start_lock);
// 	while (i < diner->nb_philos)
// 	{
// 		if (pthread_create(&diner->philos[i].thread, \
// 					NULL, &routine, &diner->philos[i]) != 0)
// 		{
// 			diner->flag_start = -1;
// 			pthread_mutex_unlock(&diner->start_lock);
// 			ft_join(diner, philos, butler, i);
			// if (pthread_join(butler, NULL) != 0)
			// 	return (ft_safe_exit(diner, ERR_JOIN_THREAD), -1);
			// while (j < i)
			// {
			// 	if (pthread_join(philos[j].thread, NULL) != 0)
			// 		return (ft_safe_exit(diner, ERR_JOIN_THREAD), -1);
			// 	j++;
			// }
// 			return (ft_safe_exit(diner, ERR_CREATE_THREAD), -1);
// 		}
// 		i++;
// 	}
// 	diner->flag_start = 1;
// 	pthread_mutex_unlock(&diner->start_lock);
// 	i = 0;
// 	if (pthread_join(butler, NULL) != 0)
// 		return (ft_safe_exit(diner, ERR_JOIN_THREAD), -1);
// 	while (i < diner->nb_philos)
// 	{
// 		if (pthread_join(philos[i].thread, NULL) != 0)
// 			return (ft_safe_exit(diner, ERR_JOIN_THREAD), -1);
// 		i++;
// 	}
// 	return (0);
// }