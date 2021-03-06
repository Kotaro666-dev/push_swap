/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:21 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 15:48:47 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sa
** swap a - swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements).
*/

#include "commands.h"

void	swap_a(t_main *main)
{
	int		temp_value;
	t_stack	**stack_a;

	stack_a = &(main->stack_a);
	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		print_out_stack_and_clear_screen(main);
		return ;
	}
	temp_value = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = temp_value;
	print_out_stack_and_clear_screen(main);
}
