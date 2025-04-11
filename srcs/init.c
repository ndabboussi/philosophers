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

#include "../include/philo.h"

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


t_philos	init_philos(int i, int meals)
{
	t_philos	philo;

	philo.id = i;
	printf("crea= %i\n\n", philo.id);
	philo.meals_goal = meals;
	philo.meals_eaten = 0;
	philo.eating = 0;
	philo.sleeping = 0;
	philo.start_time = 0;
	philo.last_meal_time = 0;
	//pthread_t		thread;
	// pthread_mutex_t	*r_fork;
	// pthread_mutex_t	*l_fork;
	// pthread_mutex_t	*write_lock;
	// pthread_mutex_t	*dead_lock;
	// pthread_mutex_t	*meal_lock;
	return (philo);
}

void	init_diner(t_symposium *diner, int ac, char **av)
{
	t_philos	*philos;
	t_philos	*tmp;
	int			i;
	int			meals;

	i = 0;
	meals = 0;
	if (ac == 6)
		meals = ft_atoi(av[5]);
	philos = (t_philos *)ft_calloc(sizeof(t_philos), ft_atoi(av[1]) + 1);
	diner->dead = 0;
	//size_t			start_time;
	diner->nb_philos = ft_atoi(av[1]);
	diner->time_die = ft_atoi(av[2]);
	diner->time_eat = ft_atoi(av[3]);
	diner->time_sleep = ft_atoi(av[4]);
	printf("philos= %d\ndie= %d\n eat= %d\nsleep= %d\nmeals= %d\n", diner->nb_philos, diner->time_die, diner->time_eat, diner->time_sleep, meals);
	tmp = philos;
	while (i < diner->nb_philos)
	{
		tmp[i] = init_philos(i + 1, meals);
		printf("philo= %i\n", tmp->id);
		i++;
	}
	diner->philos = philos;
	//pthread_mutex_t	dead_lock;
	//pthread_mutex_t	meal_lock;
	//pthread_mutex_t	write_lock;
}
