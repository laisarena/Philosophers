/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:14:45 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/07 14:55:57 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
{
	(void)philo;
	printf("%d %d is eating\n",
		delta_time(philo->param->time.init),
		philo->index);
	sleeep_ms(philo->param->time.to_eat);
	return (TRUE);
}

int	thinking(t_philo *philo)
{
	(void)philo;
	printf("%d %d is thinking\n",
		delta_time(philo->param->time.init),
		philo->index);
	return (TRUE);
}

int	sleeping(t_philo *philo)
{
	(void)philo;
	printf("%d %d is sleeping\n",
		delta_time(philo->param->time.init),
		philo->index);
	sleeep_ms(philo->param->time.to_sleep);
	return (TRUE);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = NULL;
	philo = (t_philo *)arg;
	while (eating(philo) && sleeping(philo) && thinking(philo))
		continue ;
	return (SUCCESS);
}

int	create_philo_threads(t_philo **philo)
{
	t_pthread	thread;

	while (*philo)
	{
		if (pthread_create(&thread, NULL, routine, *philo))
			return (FAIL);
		(*philo)->thread = thread;
		philo++;
	}
	return (SUCCESS);
}

int	join_philo_threads(t_philo **philo)
{
	while (*philo)
	{
		if (pthread_join((*philo)->thread, NULL))
			return (FAIL);
		philo++;
	}
	return (SUCCESS);
}

int	start_routines(t_philo **philos, t_microsec *init)
{
	*init = get_time();
	if (create_philo_threads(philos))
		return (FAIL);
	if (join_philo_threads(philos))
		return (FAIL);
	return (SUCCESS);
}
