/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:30 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/14 09:08:57 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pb
** push b - take the first element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

#include "commands.h"

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *head_stack_a;
	t_stack *temp;

	if ((*stack_a) == NULL)
	{
		return ;
	}
	head_stack_a = *stack_a;
	*stack_a = head_stack_a->next;
	if (*stack_b == NULL)
	{
		*stack_b = head_stack_a;
		(*stack_a)->prev = NULL;
		(*stack_a)->next = NULL;
		return ;
	}
	temp = *stack_b;
	*stack_b = head_stack_a;
	(*stack_b)->prev = NULL;
	(*stack_b)->next = temp;
}
