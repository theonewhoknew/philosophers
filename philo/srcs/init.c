/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:18:00 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/10/01 10:55:30 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

static void	assign_args(int argc, char **argv, t_param *param)
{
	param->n = ft_atoi(argv[1]);
	param->tdie = ft_atoi(argv[2]);
	param->teat = ft_atoi(argv[3]);
	param->tsleep = ft_atoi(argv[4]);
	if (argv[5])
		param->max_iters = ft_atoi(argv[5]);
	else
		param->max_iters = -1;
}

int	init_params(int argc, char **argv, t_param *p)
{
	int	i;

	i = -1;
	assign_args(argc, argv, p);
	pthread_mutex_init(&p->m_end, NULL);
	pthread_mutex_init(&p->m_print, NULL);
	p->start = 0;
	p->ready = 0;
	p->end = 0;
	p->fork = (pthread_mutex_t *)malloc(sizeof (pthread_mutex_t) * p->n);
	if (!p->fork)
	{
		perror("malloc failed; ");
		return (1);
	}
	while (++i < p->n)
		pthread_mutex_init(&(p->fork[i]), NULL);
	return (0);
}

t_philo	*init_philo(t_param *p, t_philo *philo)
{
	int	i;

	philo = (t_philo *)malloc(sizeof (t_philo) * p->n);
	if (!philo)
	{
		perror("malloc failed; ");
		return (NULL);
	}
	p->philo = philo;
	i = -1;
	while (++i < p->n)
	{
		philo[i].id = i;
		philo[i].dead = 0;
		philo[i].iters = 0;
		philo[i].thread_start = 0;
		philo[i].last_meal = 0;
		philo[i].par = p;
		philo[i].l_f = &p->fork[i];
		if (i == p->n - 1)
			philo[i].r_f = &p->fork[0];
		else
			philo[i].r_f = &p->fork[i + 1];
	}
	return (philo);
}
