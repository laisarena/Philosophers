/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:36:41 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/03 10:36:22 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "utils.h"

# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define FAIL		-1

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_pthread;

typedef struct s_time
{
	long int	init;
	int			to_die;
	int			to_eat;
	int			to_sleep;
}	t_time;

typedef struct s_param
{
	int		number_of_philo;
	int		must_eat;
	t_time	time;
}	t_param;

typedef struct s_hand
{
	t_mutex	*left;
	t_mutex	*right;
}	t_hand;

typedef struct s_philo
{
	int			index;
	t_hand		hand;
	t_pthread	thread;
	t_param		*param;
}	t_philo;

int		parse_input(int argc, char **argv, t_param *param);
int		initialize_structures(t_philo ***philos, t_mutex ***forks,
			t_param *param, int size);
int		create_philos(t_philo ***philos, t_mutex **forks,
			t_param *param, int size);
int		start_routines(t_philo **philos);
void	sleeep_ms(int time);

#endif
