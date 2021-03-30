/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:36 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 12:54:25 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rb
** rotate b - shift up all elements of stack b by 1.
** The first element becomes the last one.
*/

#include "commands.h"

void	rotate_b_stdout(t_main *main)
{
	rotate_b(main);
	print_out_stack_and_clear_screen(main);
	ft_putendl_fd("rb", STDOUT_FILENO);
}
