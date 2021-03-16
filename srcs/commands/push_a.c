/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:26 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 15:18:37 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pa
** push a - take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

#include "commands.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *head_stack_b;
	t_stack *temp;

	if ((*stack_b) == NULL)
	{
		return ;
	}
	head_stack_b = *stack_b;
	*stack_b = head_stack_b->next;
	if (*stack_a == NULL)
	{
		*stack_a = head_stack_b;
		(*stack_a)->prev = NULL;
		(*stack_a)->next = NULL;
		return ;
	}
	temp = *stack_a;
	*stack_a = head_stack_b;
	temp->prev = head_stack_b;
	(*stack_a)->prev = NULL;
	(*stack_a)->next = temp;
}
