/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_eat_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:20:09 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/28 10:56:17 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <unistd.h>

int	p_think(t_philo *p, int id, int *delay)
{
/* 	if (p->death == 1 || p->eaten == 1)
		return (1); */
	p->eating[id - 1] = 0;
	printf("%llu %d is thinking\n", get_time(p), id);
	if (*delay == 0 && (id % 2) != 0)
	{
		ft_usleep(p->teat * 0.9 + 1);
		*delay = 1;
	}
	return (0);
}

int	p_eat(t_philo *p, int id)
{
	grab_forks(p, id);
	p->eating[id - 1] = 1;
/* 	if (p->death == 1 || p->eaten == 1)
		return (1); */
	printf("%llu %d is eating\n", get_time(p), id);
	ft_usleep(p->teat);
/* 	if (p->death == 1 || p->eaten == 1)
		return (1); */
	if (p->opt == 1 && p->eaten_enough[id - 1] != 1)
	{
		++p->times_eaten[id - 1];
		if (p->times_eaten[id - 1] == p->neat)
			p->eaten_enough[id - 1] = 1;
	}
	release_forks(p, id);
	return (0);
}

int	p_sleep(t_philo *p, int id)
{
/* 	if (p->death == 1 || p->eaten == 1)
		return (1); */
	p->eating[id - 1] = 0;
	printf("%llu %d is sleeping\n", get_time(p), id);
	ft_usleep(p->tsleep);
	return (0);
}
