/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:15:59 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/28 17:44:50 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	release_all(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->n)
	{
		pthread_mutex_unlock(&param->fork[i]);
		i++;
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_f);
	pthread_mutex_unlock(philo->r_f);
}

static void	one_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_f);
	printf("%llu %d has taken left fork\n", get_time(philo->par), philo->id + 1);
}

int	grab_forks(t_philo *philo)
{
	if (philo->par->n == 1)
		one_fork(philo);
	else
	{
		pthread_mutex_lock(philo->l_f);
		printf("%llu %d has taken left fork\n", get_time(philo->par), philo->id + 1);
		pthread_mutex_lock(philo->r_f);
		printf("%llu %d has taken right fork\n", get_time(philo->par), philo->id + 1);
	}
	return (0);
}
