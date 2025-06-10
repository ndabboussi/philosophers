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

# define ERR_NB "Error: Invalid nb of arguments\n"
# define ERR_ARGS "Error: Invalid arguments\n"
# define ERR_USAGE "Usage: ./philo [nb_of_philosophers] [time_to_die] \
[time_to_eat] [time_to_sleep] \
(option: [nb_of_times_each_philosopher_must_eat])\n"
# define ERR_NB_PHILO "Error: Invalid number of philosophers\n"
# define ERR_NB_EAT "Error: Invalid number time to eat\n"
# define ERR_NB_SLEEP "Error: Invalid number time to sleep\n"
# define ERR_NB_DIE "Error: Invalid time before dying value\n"
# define ERR_NB_MEALS "Error: Invalid number of meals\n"

# define ERR_ALLOC "Error: Alloc failed\n"
# define ERR_CREATE_THREAD "Error: Failed to create thread\n"
# define ERR_JOIN_THREAD "Error: Failed to join threads\n"

typedef struct s_philos
{
	int				*flag_start;
	int				id;
	int				*dead;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_philos;
	int				meals_goal;
	int				meals_eaten;
	int				eating;
	int				sleeping;
	int				*full;
	size_t			start_time;
	size_t			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*start_lock;
	pthread_mutex_t	*exit_routine_lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
}	t_philos;

typedef struct s_symposium
{
	int				flag_start;
	int				dead;
	int				nb_philos;
	size_t			start_time;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meals_goal;
	int				count_full_philos;
	pthread_mutex_t	start_lock;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	t_philos		*philos;
}	t_symposium;

//input
int		check_input(int ac, char **av);

//init
int		init_diner(t_symposium *diner, char **av);
void	init_philos(t_symposium *diner, t_philos *philos, char **av);
int		init_philos_threads(t_symposium *diner, t_philos *philos);

//utils
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *number);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
//utils2
void	ft_print_msg(t_philos *philo, char *msg);
void	tragic_announcement(t_philos *philo, char *msg);
void	ft_safe_exit(t_symposium *diner, char *str);

//time
size_t	ft_get_time(void);
int		ft_usleep(size_t ms);

//routine
void	*routine(void *arg);

//eat
void	ft_eat(t_philos *philo);

//monitoring
int		check_death(t_philos *philo);
void	*monitoring(void *arg);

//print
void	ft_print_philo(t_philos *philo, int i);
void	ft_print_diner(t_symposium *diner, int option);

#endif
