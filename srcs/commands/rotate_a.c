/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:32 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 15:48:39 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ra
** rotate a - shift up all elements of stack a by 1.
** The first element becomes the last one.
*/

#include "commands.h"

void	rotate_a(t_main *main)
{
	t_stack **stack_a;

	stack_a = &(main->stack_a);
	if (*stack_a == NULL)
	{
		print_out_stack_and_clear_screen(main);
		return ;
	}
	*stack_a = (*stack_a)->next;
	print_out_stack_and_clear_screen(main);
}
