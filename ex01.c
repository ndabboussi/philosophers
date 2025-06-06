# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

int	mails = 0;
pthread_mutex_t mutex;

void	*routine()
{
	int i = 0;
	printf("    Test from threads\n");
	//sleep(3);
	while (i < 10000000)
	{
		pthread_mutex_lock(&mutex);
		i++;
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	printf("    Ending thread\n");
	return (0);
}

int	main(int ac, char **av)
{
	pthread_t	th[8];
	int			i = 0;

	pthread_mutex_init(&mutex, NULL);
	while (i < 8)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
		{
			perror("Failed to create thread\n");
			return (1);
		}
		printf("Thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (2);
		printf("Thread %d has finished\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("Nb of mails: %d\n", mails);
	return (0);
}
/* mutex is protecting a part of the code from other threads
executing it at the same time */