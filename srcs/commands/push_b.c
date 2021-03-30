/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:30 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 15:48:16 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pb
** push b - take the first element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

#include "commands.h"

void	push_b(t_main *main)
{
	t_stack **stack_a;
	t_stack **stack_b;
	t_stack *head_stack_a;

	stack_a = &(main->stack_a);
	stack_b = &(main->stack_b);
	if (*stack_a == NULL)
	{
		print_out_stack_and_clear_screen(main);
		return ;
	}
	head_stack_a = *stack_a;
	if (head_stack_a == (*stack_a)->next)
		*stack_a = NULL;
	else
		remove_head_node(&(stack_a), head_stack_a);
	if (*stack_b == NULL)
	{
		insert_node_at_front(&(stack_b), head_stack_a);
	}
	else
	{
		insert_node_at_end(&(stack_b), head_stack_a);
		*stack_b = (*stack_b)->prev;
	}
	print_out_stack_and_clear_screen(main);
}
