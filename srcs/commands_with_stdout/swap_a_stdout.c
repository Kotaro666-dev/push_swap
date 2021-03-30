/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:21 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 16:02:44 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sa
** swap a - swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements).
*/

#include "commands.h"

void	swap_a_stdout(t_main *main)
{
	swap_a(main);
	ft_putendl_fd("sa", STDOUT_FILENO);
}
