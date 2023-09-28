/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:20:09 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/28 17:18:36 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <unistd.h>

void	p_eat(t_philo *philo)
{
	grab_forks(philo);
	printf("%llu %d is eating\n", get_time(philo->par), philo->id);
	ft_usleep(philo->par->teat);
	philo->iters++;
	release_forks(philo);
}

void	p_sleep_think(t_philo *philo)
{
	printf("%llu %d is sleeping\n", get_time(philo->par), philo->id);
	ft_usleep(philo->par->tsleep);
	printf("%llu %d is thinking\n", get_time(philo->par), philo->id);
}
