/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:04:42 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/10/03 13:06:48 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int64_t n)
{
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n <= 9)
		ft_putchar(n + '0');
}

void	print_aux(int64_t ms, int id, char *str)
{
	ft_putnbr(ms);
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

int	check_death(t_philo *philo)
{
	int	end;

	end = 0;
	pthread_mutex_lock(&(philo->par->m_end));
	if (philo->par->end == 1)
		end = 1;
	pthread_mutex_unlock(&(philo->par->m_end));
	return (end);
}
