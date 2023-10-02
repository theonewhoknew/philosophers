/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:15:59 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/29 10:16:32 by theonewhokn      ###   ########.fr       */
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
	print_state(philo, FORK);
	while (!philo->par->end)
		continue ;
}

int	grab_forks(t_philo *philo)
{
	if (philo->par->n == 1)
		one_fork(philo);
	else
	{
		pthread_mutex_lock(philo->l_f);
		print_state(philo, FORK);
		pthread_mutex_lock(philo->r_f);
		print_state(philo, FORK);
	}
	return (0);
}
