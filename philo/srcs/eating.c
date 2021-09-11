/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:08:35 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/10 21:45:12 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	t_mutex	*first;
	t_mutex	*second;

	first = philo->hand.left;
	second = philo->hand.right;
	pthread_mutex_lock(first);
	print("has taken a fork\n", philo);
	pthread_mutex_lock(second);
	print("has taken a fork\n", philo);
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->hand.left);
	pthread_mutex_unlock(philo->hand.right);
}

int	eating(t_philo *philo)
{
	if (philo->param->died.index != 0)
		return (FALSE);
	take_forks(philo);
	philo->last_meal = get_time();
	print("is eating\n", philo);
	sleeep_ms(philo->param->time.to_eat);
	drop_forks(philo);
	return (TRUE);
}
