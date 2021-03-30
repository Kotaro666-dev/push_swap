/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:36 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 15:48:42 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rb
** rotate b - shift up all elements of stack b by 1.
** The first element becomes the last one.
*/

#include "commands.h"

void	rotate_b(t_main *main)
{
	t_stack **stack_b;

	stack_b = &(main->stack_b);
	if (*stack_b == NULL)
	{
		print_out_stack_and_clear_screen(main);
		return ;
	}
	*stack_b = (*stack_b)->next;
	print_out_stack_and_clear_screen(main);
}
