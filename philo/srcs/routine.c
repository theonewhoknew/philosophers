/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:39 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/09/28 12:20:02 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

void	routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (!philo->par->ready)
		continue ;
	if (philo->id + 1 % 2 != 0)
		ft_usleep(philo->par->teat * 0.9 + 1);
	while (philo->par->death != 1 && philo->par->eaten != 1)
	{
		p_eat(philo);
		p_sleep_think(philo);
	}
}
