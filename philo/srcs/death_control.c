/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:40:44 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/10 21:44:03 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*death_control(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (delta_time(philo->last_meal, FALSE) < philo->param->time.to_die
		&& philo->param->died.index == 0)
		continue ;
	if (philo->param->died.index == 0)
	{
		pthread_mutex_lock(&philo->param->died.mutex);
		philo->param->died.time = get_time();
		philo->param->died.index = philo->index;
		pthread_mutex_unlock(&philo->param->died.mutex);
		pthread_mutex_unlock(philo->hand.left);
	}
	return (SUCCESS);
}

void	create_control_thread(t_philo *philo)
{
	t_pthread	thread;

	pthread_create(&thread, NULL, death_control, philo);
	pthread_detach(thread);
}
