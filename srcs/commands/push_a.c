/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:26 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 17:08:26 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pa
** push a - take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

#include "commands.h"

void			push_a(t_main *main)
{
	t_stack **stack_a;
	t_stack **stack_b;
	t_stack *head_stack_b;

	stack_a = &(main->stack_a);
	stack_b = &(main->stack_b);
	if (*stack_b == NULL)
	{
		print_out_stack_and_clear_screen(main);
		return ;
	}
	head_stack_b = *stack_b;
	if (head_stack_b == (*stack_b)->next)
		*stack_b = NULL;
	else
		remove_head_node(&(stack_b), head_stack_b);
	if (*stack_a == NULL)
		insert_node_at_front(&(stack_a), head_stack_b);
	else
	{
		insert_node_at_end(&(stack_a), head_stack_b);
		*stack_a = (*stack_a)->prev;
	}
	print_out_stack_and_clear_screen(main);
}
