/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 10:01:18 by ndabbous          #+#    #+#             */
/*   Updated: 2025-04-11 10:01:18 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

# define RED "\033[31;01m"
# define RESET "\033[00m"

typedef struct s_philos
{
	int				id;
	int				meals_goal;
	int				meals_eaten;
	int				eating;
	int				sleeping;
	size_t			start_time;
	size_t			last_meal_time;
	//pthread_t		thread;
	// pthread_mutex_t	*r_fork;
	// pthread_mutex_t	*l_fork;
	// pthread_mutex_t	*write_lock;
	// pthread_mutex_t	*dead_lock;
	// pthread_mutex_t	*meal_lock;

}	t_philos;

typedef struct s_symposium
{
	int				dead;
	int				nb_philos;
	size_t			start_time;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	//pthread_mutex_t	dead_lock;
	//pthread_mutex_t	meal_lock;
	//pthread_mutex_t	write_lock;
	t_philos		*philos;
}	t_symposium;


//input
int		check_input(int ac, char **av);

//init
void	init_diner(t_symposium *diner, int ac, char **av);

#endif