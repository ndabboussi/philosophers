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

int	ft_atoi(const char *number)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((number[i] >= 9 && number[i] <= 13) || number[i] == 32)
		i++;
	if (number[i] == '+' || number[i] == '-')
	{
		if (number[i] == '-')
			sign = -1;
		i++;
	}
	while (number[i] >= '0' && number[i] <= '9')
	{
		nb = nb * 10 + (number[i] - 48);
		i++;
	}
	return (nb * sign);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}


void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (nmemb < 0 || size < 0)
		return (NULL);
	str = (char *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, (size * nmemb));
	return (str);
}


void	init_philos(t_symposium *diner, t_philos *philos, int meals)
{
	int	i;

	i = 0;
	//printf("init_philos= %i\n\n", philos->id);
	while (i != diner->nb_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_goal = meals;
		philos[i].meals_eaten = 0;
		philos[i].eating = 0;
		philos[i].sleeping = 0;
		philos[i].start_time = 0;
		philos[i].last_meal_time = 0;
	//	ft_print_node(&philos[i]);
		i++;
	}
	//pthread_t		thread;
	// pthread_mutex_t	*r_fork;
	// pthread_mutex_t	*l_fork;
	// pthread_mutex_t	*write_lock;
	// pthread_mutex_t	*dead_lock;
	// pthread_mutex_t	*meal_lock;
}

// void	init_threads(t_symposium *diner, t_philos *philos)
// {
// 	int	i;

// 	i = 0;
// 	//printf("init_threads\n\n");
// 	while (i != diner->nb_philos)
// 	{
// 		philos[i].thread = pthread_create();
// // 		philos[i].r_fork;
// // 		philos[i].l_fork;
// // 		philos[i].dead_lock;
// // 		philos[i].meal_lock;
// 		i++;
// 	}
// }
void	init_diner(t_symposium *diner, int ac, char **av)
{
	int			i;
	int			meals;
	t_philos	*philos;

	i = 0;
	meals = 0;
	if (ac == 6)
		meals = ft_atoi(av[5]);
	philos = (t_philos *)ft_calloc(sizeof(t_philos), ft_atoi(av[1]) + 1);
	if (!philos)
		//safe_exit();
	diner->dead = 0;
	//size_t			start_time;
	diner->nb_philos = ft_atoi(av[1]);
	diner->time_die = ft_atoi(av[2]);
	diner->time_eat = ft_atoi(av[3]);
	diner->time_sleep = ft_atoi(av[4]);
	//printf("philos= %d\ndie= %d\neat= %d\nsleep= %d\nmeals= %d\n", diner->nb_philos, diner->time_die, diner->time_eat, diner->time_sleep, meals);
	init_philos(diner, philos, meals);
	//init_threads(diner, philos);
	//pthread_mutex_t	dead_lock;
	//pthread_mutex_t	meal_lock;
	//pthread_mutex_t	write_lock;
}
