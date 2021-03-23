/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:43:59 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/23 14:06:06 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			print_out_ok(void)
{
	ft_putendl_fd("OK", STDOUT_FILENO);
	return (SUCCESS);
}

int			print_out_ko(t_main *main)
{
	dispose_memory(main);
	ft_putendl_fd("KO", STDOUT_FILENO);
	return (SUCCESS);
}

int			print_out_error(t_main *main)
{
	dispose_memory(main);
	ft_putendl_fd("ERROR", STDERR_FILENO);
	system("leaks push_swap");
	return (ERROR);
}

int			print_out_null_character(void)
{
	ft_putstr_fd("\0", STDOUT_FILENO);
	return (SUCCESS);
}
