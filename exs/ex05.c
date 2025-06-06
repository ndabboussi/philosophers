#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

pthread_mutex_t	mutex;

void	*routine(void *arg)
{
	pthread_mutex_lock(&mutex);
	printf("Got lock\n");
	sleep(1);
	pthread_mutex_unlock(&mutex);
	return (0);
}

int	main(int ac, char **av)
{
	pthread_t	th[4];
	int			i;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Error at thread creation\n");
		sleep(1);
		i++;
	}
	while (i < 4)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Error at thread joining\n");
		i++;
	}
}
