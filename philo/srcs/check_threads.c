/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:14:45 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/10/03 12:15:00 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

static void	make_end(t_philo *ph, t_param *p, int i, int type)
{
	pthread_mutex_lock(&(p->m_end));
	p->end = 1;
	pthread_mutex_unlock(&(p->m_end));
	if (type == 1)
		print_end(&ph[i], DIE);
	else
		print_end(&ph[i], ITERS);
}

static int64_t	get_last(t_philo *ph, int i)
{
	int64_t	last;

	pthread_mutex_lock(&ph[i].m_last);
	last = ph[i].last;
	pthread_mutex_unlock(&ph[i].m_last);
	return (last);
}

static int	is_dead(int64_t elapsed, t_param *p, t_philo *ph, int i)
{
	if (elapsed > p->tdie)
	{
		make_end(ph, p, i, 1);
		return (1);
	}
	return (0);
}

static int	has_eaten(int iters, t_param *p, t_philo *ph, int i)
{
	if (p->max_iters > 0 && iters > p->max_iters)
	{
		make_end(ph, p, i, 2);
		return (1);
	}
	return (0);
}

void	check_threads(t_param *p, t_philo *ph)
{
	int		i;
	int		iters;
	int64_t	elapsed;
	int64_t	last;

	while (!p->end)
	{
		i = -1;
		while (++i < p->n)
		{
			last = get_last(ph, i);
			elapsed = get_time(p) - last;
			if (is_dead(elapsed, p, ph, i))
				return ;
			pthread_mutex_lock(&ph[i].m_iters);
			iters = ph[i].iters;
			pthread_mutex_unlock(&ph[i].m_iters);
			if (has_eaten(iters, p, ph, i))
				return ;
		}
	}
}
