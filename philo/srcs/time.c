/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:24:22 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/08 11:45:08 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define	DELAY 0
t_microsec	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	delta_time(t_microsec init)
{
	t_microsec	now;
	t_microsec	delta;

	now = get_time();
	delta = now - init;
	return (delta / 1000);
}

void	sleeep_ms(int time)
{
	int	x;

	x = (200000 - DELAY) / 200;
	usleep(time * x);
}
