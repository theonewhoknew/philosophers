/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:18:00 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/26 12:58:55 by dtome-pe         ###   ########.fr       */
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

static void	assign_args(int argc, char **argv, t_philo *p)
{
	p->n = ft_atoi(argv[1]);
	p->tdie = ft_atoi(argv[2]);
	p->teat = ft_atoi(argv[3]);
	p->tsleep = ft_atoi(argv[4]);
}

int	init_struct(int argc, char **argv, t_philo *p)
{
	assign_args(argc, argv, p);
	p->philo = NULL;
	p->timer = NULL;
	p->mutex = NULL;
	p->eating = NULL;
	if (argc == 6)
	{
		p->opt = 1;
		p->neat = ft_atoi(argv[5]);
		p->all_have_eaten = 0;
		p->times_eaten = NULL;
		p->eaten_enough = NULL;
		p->supervisor = NULL;
	}
	else
		p->opt = 0;
	p->death = 0;
	return (0);
}
