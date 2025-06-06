#include "philo.h"

void	ft_print_philo(t_philos *philo, int i)
{
	printf("[PHILO N %i]\n", i + 1);
	printf("    Philos id = %i\n", philo->id);
	printf("    Dead ? [%i]\n", philo->dead);
	printf("    Meals_eaten= %i/%i\n", philo->meals_eaten, philo->meals_goal);
	printf("    Eating ? %i\n", philo->eating);
	printf("    Sleeping ? %i\n", philo->sleeping);
	printf("    Start= = %zu\n", philo->start_time);
	printf("    Last meal = %zu\n", philo->last_meal_time);

	printf("\n");
}

void	ft_print_diner(t_symposium *diner, int option)
{
	(void)option;
	printf("[DINER]\n");
	printf(" >start_time = %zu\n", diner->start_time);
	printf(" >dead or alive ? [%i]\n", diner->dead);
	printf(" >nb_philos= %d\n", diner->nb_philos);
	printf(" >time_die= %d\n", diner->time_die);
	printf(" >time_eat= %d\n", diner->time_eat);
	printf(" >time_sleep= %d\n", diner->time_sleep);
	printf("\n");
}
