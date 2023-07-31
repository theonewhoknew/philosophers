#include "../inc/philo.h"
#include <stdio.h>

void	release_all(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->n)
	{
		pthread_mutex_unlock(philo->mutex[i]);
		i++;
	}
}

void	release_forks(t_philo *philo, int id)
{
	if (id == 1)
	{
		pthread_mutex_unlock(philo->mutex[0]);
		pthread_mutex_unlock(philo->mutex[philo->n - 1]);
	}
	else
	{
		pthread_mutex_unlock(philo->mutex[id - 1]);
		pthread_mutex_unlock(philo->mutex[id - 2]);
	}
}

static void	one_fork(t_philo *philo, int id)
{	
	pthread_mutex_lock(philo->mutex[0]);
	printf("%llu %d has taken a fork\n", get_time(), id);
	while (philo->death != 1)
		;
}

static int philosoper_one(t_philo *philo, int id)
{
	if (philo->death == 1 || philo->all_have_eaten == 1)
		return (1);
	pthread_mutex_lock(philo->mutex[0]);
	printf("%llu %d has taken a fork\n", get_time(), id);
	if (philo->death == 1 || philo->all_have_eaten == 1)
		return (1);
	pthread_mutex_lock(philo->mutex[philo->n - 1]);
	printf("%llu %d has taken a fork\n", get_time(), id);
	return (0);
}

int	grab_forks(t_philo *philo, int id)
{	
	if (philo->n == 1)
		one_fork(philo, id);
	else
	{
		if (id == 1)
			return (philosoper_one(philo, id));
		else
		{	
			pthread_mutex_lock(philo->mutex[id - 1]);
			if (philo->death == 1 || philo->all_have_eaten == 1)
				return (1);
			printf("%llu %d has taken a fork\n", get_time(), id);
			pthread_mutex_lock(philo->mutex[id - 2]);
			if (philo->death == 1 || philo->all_have_eaten == 1)
				return (1);
			printf("%llu %d has taken a fork\n", get_time(), id);
		}
	}
	return (0);
}