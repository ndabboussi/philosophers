#include "philo.h"

void	ft_print_node(t_philos *philos)
{
	printf("Philos id = %i\n", philos->id);
	printf("meal_goal = %i, meals_eaten= %i\n", philos->meals_goal, philos->meals_eaten);
	printf("Eating ? %i\n", philos->eating);
	printf("Sleeping ? %i\n", philos->sleeping);
	//printf("Start= = %i\n", philos->start_time);
	//printf("Last meal = %i\n", philos->last_meal_time);
	printf("\n");
}

