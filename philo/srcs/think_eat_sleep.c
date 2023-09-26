/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_eat_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:20:09 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/06 11:47:59 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <unistd.h>

int	p_think(t_philo *philo, int id, int *delay)
{
	if (philo->death == 1 || philo->all_have_eaten == 1)
		return (1);
	printf("%llu %d is thinking\n", get_time(philo), id);
/* 	if (*delay == 0 && (id % 2) != 0)
	{	
		ft_usleep(philo->teat * 0.1);
		*delay = 1;
		printf("%llu, philo %d was delayed %f\n", get_time(philo), id, philo->teat * 0.1);
	} */
	return (0);
}

int	p_eat(t_philo *philo, int id)
{
	if (grab_forks(philo, id) == 1)
		return (1);
	philo->eating[id - 1] = 1;
	if (philo->death == 1 || philo->all_have_eaten == 1)
		return (1);
	printf("%llu %d is eating\n", get_time(philo), id);
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
	philo->eating[id - 1] = 0;
	printf("%llu %d is sleeping\n", get_time(philo), id);
	ft_usleep(philo->tsleep);
	if (philo->death == 1 || philo->all_have_eaten == 1)
		return (1);
	return (0);
}
