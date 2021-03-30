/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_and_b_stdout.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:38 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 12:54:19 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rr
** ra and rb at the same time.
*/

#include "commands.h"

void	rotate_a_and_b_stdout(t_main *main)
{
	rotate_a_and_b(main);
	print_out_stack_and_clear_screen(main);
	ft_putendl_fd("rr", STDOUT_FILENO);
}
