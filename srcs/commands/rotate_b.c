/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:36 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/15 08:57:19 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rb
** rotate b - shift up all elements of stack b by 1.
** The first element becomes the last one.
*/

#include "commands.h"

void	rotate_b(t_stack **stack_b)
{
	t_stack *tail;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		return ;
	}
	tail = *stack_b;
	// GET TAIL NODE
	while (tail->next)
	{
		tail = tail->next;
	}
	// REMOVE TAIL NODE FROM STACK
	while ((*stack_b)->next->next)
	{
		*stack_b = (*stack_b)->next;
	}
	(*stack_b)->next = NULL;

	// ADD TAIL NODE TO HEAD
	tail->prev = NULL;
	tail->next = (*stack_b);
	(*stack_b)->prev = tail;
	(*stack_b)->next = (*stack_b)->next->next;
	while ((*stack_b)->next)
	{
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b)->prev = NULL;
	(*stack_b)->next = NULL;
	(*stack_b)->prev->next = NULL;
	while ((*stack_b)->prev)
	{
		(*stack_b) = (*stack_b)->prev;
	}
}
