/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:18:44 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 12:54:36 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sb
** swap b - swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements).
*/

#include "commands.h"

void	swap_b_stdout(t_main *main)
{
	swap_b(main);
	print_out_stack_and_clear_screen(main);
	ft_putendl_fd("sb", STDOUT_FILENO);
}
