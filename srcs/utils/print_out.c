/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:43:59 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 16:54:45 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			print_out_ok(t_main *main)
{
	if (main->option.is_c)
	{
		ft_putstr_fd(GREEN, STDOUT_FILENO);
		ft_putendl_fd("OK", STDOUT_FILENO);
		ft_putstr_fd(RESET, STDOUT_FILENO);
	}
	else
	{
		ft_putendl_fd("OK", STDOUT_FILENO);
	}
	return (SUCCESS);
}

int			print_out_ko(t_main *main)
{
	dispose_memory(main);
	if (main->option.is_c)
	{
		ft_putstr_fd(RED, STDOUT_FILENO);
		ft_putendl_fd("KO", STDOUT_FILENO);
		ft_putstr_fd(RESET, STDOUT_FILENO);
	}
	else
	{
		ft_putendl_fd("KO", STDOUT_FILENO);
	}
	return (SUCCESS);
}

int			print_out_error(t_main *main)
{
	dispose_memory(main);
	if (main->option.is_c)
	{
		ft_putstr_fd(MAGNETA, STDOUT_FILENO);
		ft_putendl_fd("Error", STDOUT_FILENO);
		ft_putstr_fd(RESET, STDOUT_FILENO);
	}
	else
	{
		ft_putendl_fd("Error", STDERR_FILENO);
	}
	return (ERROR);
}

int			print_out_null_character(t_main *main)
{
	dispose_memory(main);
	ft_putstr_fd("\0", STDOUT_FILENO);
	return (SUCCESS);
}
