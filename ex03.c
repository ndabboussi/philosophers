#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	int	index;
	int	sum;
	int	j;

	j = 0;
	sum = 0;
	index = *(int *)arg;
	while (j < 5)
	{
		sum += primes[index + j];
		j++;
	}
	printf("Local sum = %d\n", sum);
	*(int *)arg = sum;
	return (arg);
}

int	main(int ac, char **av)
{
	pthread_t	th[2];
	int			i;
	int			global_sum = 0;
	int			*res;
	int			*a;

	i = 0;
	while (i < 2)
	{
		a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			perror("failed to create thread\n");
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (pthread_join(th[i], (void **)&res) != 0)
			perror("failed to create thread\n");
		i++;
		global_sum += *res;
		free(res);
	}
	printf("Global_sum = %d\n", global_sum);
	return (0);
}

// squat prisoner 
// pas chasse jump
// squat twist
// 3x3 remontee de genou
// skier ou fentes sautees

