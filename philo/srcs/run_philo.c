/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:39 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/09/26 12:58:43 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

void	run_philo(t_philo *p, int id)
{
	int	delay;

	delay = 0;
	while (p->death != 1 && p->all_have_eaten != 1)
	{
		if (p_think(p, id, &delay) == 1)
			return ;
		if (p_eat(p, id) == 1)
			return ;
		if (p_sleep(p, id) == 1)
			return ;
	}
}
