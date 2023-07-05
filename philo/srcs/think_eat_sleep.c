#include "../inc/philo.h"
#include <sys/time.h>
#include <stdio.h>

void	think(t_philo *philo)
{
	printf("%llu %d is thinking\n", get_timestamp(), philo->thread_id);
}