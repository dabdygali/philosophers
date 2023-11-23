/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_warn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:04:01 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/23 15:18:35 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	check_args_warn(int argc, char *argv[])
{
	int	tmp;

	if (argc < 2)
		return (0);
	tmp = ft_checkwarn_argc(argc, MIN_ARGC, MAX_ARGC);
	if (tmp <= 0)
		return (tmp);
	while (--argc > 0)
	{
		if (ft_str_is_int(argv[argc]) == 0 || ft_atoi(argv[argc]) < 0)
		{
			if (ft_putstr_fd("Invalid argument\n", STDERR_FILENO) < 0)
				return (-1);
		}
	}
	return (1);
}
