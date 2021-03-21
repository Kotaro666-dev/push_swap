/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:43:59 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 14:29:29 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			print_out_ok(void)
{
	ft_putendl_fd("OK", STDOUT_FILENO);
	return (SUCCESS);
}

int			print_out_ko(void)
{
	ft_putendl_fd("KO", STDOUT_FILENO);
	return (SUCCESS);
}

int			print_out_error(void)
{
	ft_putendl_fd("ERROR", STDERR_FILENO);
	return (ERROR);
}

int			print_out_null_character(void)
{
	ft_putstr_fd("\0", STDOUT_FILENO);
	return (SUCCESS);
}
