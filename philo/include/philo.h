/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:06:29 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/23 15:23:45 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define MIN_ARGC 5
# define MAX_ARGC 6

int		check_args_warn(int argc, char *argv[]);
int		ft_atoi(const char *str);
int		ft_checkwarn_argc(int argc, int min_argc, int max_argc);
int		ft_isdigit(int c);
int		ft_putstr_fd(const char *const s, int fd);
int		ft_str_is_int(char *str);

#endif
