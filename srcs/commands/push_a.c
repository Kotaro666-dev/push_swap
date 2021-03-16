/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:26 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 17:07:51 by kkamashi         ###   ########.fr       */
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
	head_stack_b->prev = NULL;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
	{
		(*stack_b)->prev = NULL;
	}
	if (*stack_a == NULL)
	{
		*stack_a = head_stack_b;
		head_stack_b->prev = NULL;
		head_stack_b->next = NULL;
		return ;
	}
	temp = *stack_a;
	head_stack_b->next = temp;
	temp->prev = head_stack_b;
	*stack_a = head_stack_b;
}
