/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:06:29 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/11 16:39:41 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Librires needed for this header file only */
# include <pthread.h>

# define MIN_ARGC 4 // Minimum required number of arguments (position dimension)
# if MIN_ARGC < 0
#  error "MIN_ARGC is negative"
# endif
# define MAX_ARGC 5 // Maximum allowed number of arguments (position dimension)
# if MAX_ARGC < 0 || MAX_ARGC < MIN_ARGC
#  if MAX_ARGC < 0
#   error "MAX_ARGC is negative"
#  else
#   error "MAX_ARGC is less than MIN_ARGC"
#  endif
# endif
/* Command-line argument position of "number_of_philosophers" */
# define CLA_POS_NUM_OF_PHILO 1
# if CLA_POS_NUM_OF_PHILO < 1 || CLA_POS_NUM_OF_PHILO > MAX_ARGC
#  error "CLA_POS_NUM_OF_PHILO is setup wrong"
# endif
/* Command-line argument position of "time_to_die" */
# define CLA_POS_TIME_TO_DIE 2
# if CLA_POS_TIME_TO_DIE < 1 || CLA_POS_TIME_TO_DIE > MAX_ARGC
#  error "CLA_POS_TIME_TO_DIE is setup wrong"
# endif
/* Command-line argument position of "time_to_eat" */
# define CLA_POS_TIME_TO_EAT 3
# if CLA_POS_TIME_TO_EAT < 1 || CLA_POS_TIME_TO_EAT > MAX_ARGC
#  error "CLA_POS_TIME_TO_EAT is setup wrong"
# endif
/* Command-line argument position of "time_to_sleep" */
# define CLA_POS_TIME_TO_SLEEP 4
# if CLA_POS_TIME_TO_SLEEP < 1 || CLA_POS_TIME_TO_SLEEP > MAX_ARGC
#  error "CLA_POS_TIME_TO_SLEEP is setup wrong"
# endif
/* Command-line argument position of "time_to_sleep" */
# define CLA_POS_MUST_EAT 5
# if CLA_POS_MUST_EAT < 1 || CLA_POS_MUST_EAT > MAX_ARGC
#  error "CLA_POS_MUST_EAT_ is setup wrong"
# endif

typedef struct s_mutex_resource
{
	pthread_mutex_t	lock;
	int				status;
}	t_resource;

typedef struct s_shared_resources
{
	int				total;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	t_resource		print;
	t_resource		cntrl;
	t_resource		*forks;
}	t_shared;

typedef struct s_philo_seat
{
	int				id;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	t_resource		*print;
	t_resource		*cntrl;
	t_resource		*right_fork;
	t_resource		*left_fork;
}	t_seat;

int		check_args_warn(int argc, char *argv[]);
int		ft_atoi(const char *str);
int		ft_checkwarn_argc(int argc, int min_argc, int max_argc);
int		ft_isdigit(int c);
int		ft_putstr_fd(const char *const s, int fd);
int		ft_str_is_int(char *str);
int		init_common_warn_clean(t_shared *common, int argc, char *argv[]);
int		terminate_common_warn(t_shared *common);
int		init_seats_clean(t_seat **seats, t_shared *common);
int		run_simulation(t_seat *seats, int qty);
int		lock_warn(pthread_mutex_t *mutex, pthread_mutex_t *print);
int		unlock_warn(pthread_mutex_t *mutex, pthread_mutex_t *print);
int		control_write(t_seat *seat, int status);

#endif
