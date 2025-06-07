/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-06 12:22:33 by ndabbous          #+#    #+#             */
/*   Updated: 2025-06-06 12:22:33 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr_fd("Error: gettimeofday failed\n", 2);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}

int	ft_usleep(size_t ms)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < ms)
		usleep(500);
	return (0);
}
// void	ft_sleep(t_philos *philosopher)
// {
// 	print_msg("is sleeping", philosopher->id, philosopher);
// 	ft_usleep2(philosopher->time_to_sleep, philosopher);
// }

// int	ft_usleep(size_t time)
// {
// 	size_t	start;

// 	start = current_time();
// 	while ((current_time() - start) < time)
// 		usleep(50);
// 	return (0);
// }

// int	ft_usleep2(size_t time, t_philosophers *philo)
// {
// 	size_t	start;

// 	start = current_time();
// 	while ((current_time() - start) < time && dead_check(philo) == 0)
// 		usleep(75);
// 	return (0);
// }