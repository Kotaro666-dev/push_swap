/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:32 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 12:54:22 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ra
** rotate a - shift up all elements of stack a by 1.
** The first element becomes the last one.
*/

#include "commands.h"

void	rotate_a_stdout(t_main *main)
{
	rotate_a(main);
	print_out_stack_and_clear_screen(main);
	ft_putendl_fd("ra", STDOUT_FILENO);
}
