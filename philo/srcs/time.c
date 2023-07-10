#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/philo.h"

long long get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

void timer(t_philo *philo, int id)
{	
	long long	og_time;
	int			elapsed;

	while (philo->simulation_start != 1)
		;
	while (philo->death != 1)
	{
		while (philo->thinking[id] != 1)
			;
		og_time = get_time();
		while (philo->thinking[id] == 0 && philo->death == 0)
		{	
			elapsed = get_time() - og_time;
			//printf("time to die: %d\n", philo->time_to_die / 1000);
			//printf("elapsed time: %d\n", elapsed);
			if (elapsed > philo->time_to_die / 1000)
			{	
				printf("%llu %d died\n", get_time(), id);
				philo->death = 1;
			}
		}
	}
}
