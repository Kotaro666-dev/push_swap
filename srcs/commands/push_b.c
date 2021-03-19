/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:30 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/19 20:41:24 by kkamashi         ###   ########.fr       */
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
		return ;
	}
	head_stack_a = *stack_a;
	if (head_stack_a == (*stack_a)->next)
	{
		*stack_a = NULL;
	}
	else
	{
		*stack_a = head_stack_a->next;
		(*stack_a)->prev->prev->next = *stack_a;
		(*stack_a)->prev = (*stack_a)->prev->prev;
	}
	if (*stack_b == NULL)
	{
		*stack_b = head_stack_a;
		head_stack_a->prev = head_stack_a;
		head_stack_a->next = head_stack_a;
	}
	else
	{
		head_stack_a->next = *stack_b;
		head_stack_a->prev = (*stack_b)->prev;
		(*stack_b)->prev->next = head_stack_a;
		(*stack_b)->prev = head_stack_a;
		*stack_b = (*stack_b)->prev;
	}
	main->count++;
}
