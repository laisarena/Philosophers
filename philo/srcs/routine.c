/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:14:45 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/31 20:42:12 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	return (SUCCESS);
}

int	create_philo_threads(t_philo **philo)
{
	t_pthread	thread;

	while (*philo)
	{
		thread = (*philo)->thread;
		pthread_create(&thread, NULL, routine, *philo);
		philo++;
	}
	return (SUCCESS);
}

int	join_philo_threads(t_philo **philo)
{
	t_pthread	thread;

	while (*philo)
	{
		thread = (*philo)->thread;
		pthread_join(thread, NULL);
		philo++;
	}
	return (SUCCESS);
}

int	start_routines(t_philo **philos)
{
	(void)philos;
	//create_philo_threads(philos);
	//join_philo_threads(philos);
	//return (FAIL);
	return (SUCCESS);
}
