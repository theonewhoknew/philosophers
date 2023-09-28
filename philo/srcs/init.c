/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:18:00 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/28 11:09:11 by dtome-pe         ###   ########.fr       */
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
	if (argc == 6)
	{
		param->opt = 1;
		param->neat = ft_atoi(argv[5]);
		param->eaten = 0;
	}
	else
		param->opt = 0;
}

int	init_params(int argc, char **argv, t_param *param)
{
	assign_args(argc, argv, param);
	param->start = 0;
	param->death = 0;
	return (0);
}
