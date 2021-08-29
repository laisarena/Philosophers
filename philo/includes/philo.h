/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:36:41 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/28 21:49:36 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include "utils.h"

# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define FAIL		-1

typedef struct s_time
{
	int	to_die;
	int	to_eat;
	int	to_sleep;
}	t_time;

typedef struct s_hand
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_hand;

typedef struct s_philo
{
	int		index;
	t_hand	hand;
}	t_philo;

typedef struct s_param
{
	int				number_of_philo;
	int				must_eat;
	t_time			time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_param;

int	parse_input(int argc, char **argv, t_param *param);

#endif
