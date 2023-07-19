#include "../inc/philo.h"
#include <stdio.h>
#include <unistd.h>

int	p_think(t_philo *philo, int id, int *delay)
{	
	if (philo->death == 1 || philo->all_have_eaten == 1)
		return (1);
	philo->thinking[id - 1] = 1;
	printf("%lu %d is thinking\n", get_time(), id);
	/* if ((id % 2) != 0 && *delay == 0)
	{	
		usleep(philo->teat * 0.5);
		*delay = 1;
	} */
}

int	p_eat(t_philo *philo, int id)
{
	if (grab_forks(philo, id) == 1)
		return (1);
	philo->thinking[id - 1] = 0;
	if (philo->death == 1 || philo->all_have_eaten == 1)
		return (1);
	printf("%lu %d is eating\n", get_time(), id);
	ft_usleep(philo->teat);
	if (philo->death == 1 || philo->all_have_eaten == 1)
		return (1);
	if (philo->opt == 1 && philo->eaten_enough[id - 1] != 1)
	{
		++philo->times_eaten[id - 1];
		if (philo->times_eaten[id - 1] == philo->neat)
			philo->eaten_enough[id - 1] = 1;
	}
	release_forks(philo, id);
	return (0);
}

int	p_sleep(t_philo *philo, int id)
{	
	if (philo->death == 1 || philo->all_have_eaten == 1)
		return (1);
	printf("%lu %d is sleeping\n", get_time(), id);
	ft_usleep(philo->tsleep);
}