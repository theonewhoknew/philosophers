#include "../inc/philo.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

uint64_t	get_time(void)
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		return (1);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(useconds_t time)
{
	uint64_t	start;
	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return(0);
}

void timer(t_philo *philo, int id)
{	
	long long	og_time;
	int			elapsed;

	while (philo->start != 1)
		;
	while (philo->death != 1 && philo->all_have_eaten != 1)
	{	
		while (philo->eating[id - 1] != 0)
		{
			if (philo->death == 1 || philo->all_have_eaten == 1)
				break ;
		}
		og_time = get_time();
		while (philo->eating[id - 1] != 1 && philo->death != 1 && philo->all_have_eaten != 1)
		{	
			elapsed = get_time() - og_time;
			//printf("elapsed is %d, tdie is %d\n", elapsed, philo->tdie);
			if (elapsed > philo->tdie)
			{	
				philo->death = 1;
				printf("%llu %d died\n", get_time(), id);
				release_all(philo);
			}
		}
	}
}
