#include "../inc/philo.h"
#include <stdio.h>
#include <unistd.h>

static void	grab_forks(t_philo *philo, int id)
{
	if (id == 1)
	{
		pthread_mutex_lock(philo->mutex[0]);
		printf("%llu %d has taken a fork\n", get_time(), id);
		pthread_mutex_lock(philo->mutex[philo->n - 1]);
		printf("%llu %d has taken a fork\n", get_time(), id);
	}
	else
	{
		pthread_mutex_lock(philo->mutex[id - 1]);
		printf("%llu %d has taken a fork\n", get_time(), id);
		pthread_mutex_lock(philo->mutex[id - 2]);
		printf("%llu %d has taken a fork\n", get_time(), id);
	}
}

void	p_think(t_philo *philo, int id)
{
	philo->thinking[id - 1] = 1;
	printf("%llu %d is thinking\n", get_time(), id);
}

void	p_eat(t_philo *philo, int id)
{
	grab_forks(philo, id);
	printf("%llu %d is eating\n", get_time(), id);
	philo->thinking[id - 1] = 0;
	usleep(philo->teat * 1000);
	if (philo->opt == 1 && philo->eaten_enough[id - 1] != 1)
	{
		++philo->times_eaten[id - 1];
		printf("philo  %d has eaten %d\n", id, philo->times_eaten[id - 1]);
		if (philo->times_eaten[id - 1] == philo->neat)
			philo->eaten_enough[id - 1] = 1;
	}
	release_forks(philo, id);
}

void	p_sleep(t_philo *philo, int id)
{
	printf("%llu %d is sleeping\n", get_time(), id);
	usleep(philo->tsleep * 1000);
}