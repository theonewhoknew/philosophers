/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:39 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/09/06 09:18:33 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

void	run_philo(t_philo *philo, int id)
{
	int	delay;

	delay = 0;
	philo->ready[id - 1] = 1;
	while (philo->start != 1)
		;
	while (philo->death != 1 && philo->all_have_eaten != 1)
	{
		if (p_think(philo, id, &delay) == 1)
			return ;
		if (p_eat(philo, id) == 1)
			return ;
		if (p_sleep(philo, id) == 1)
			return ;
	}
}
