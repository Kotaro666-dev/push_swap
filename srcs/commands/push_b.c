/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:30 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/19 13:55:20 by kkamashi         ###   ########.fr       */
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
	t_stack *temp;

	stack_a = &(main->stack_a);
	stack_b = &(main->stack_b);
	if (*stack_a == NULL)
	{
		return ;
	}
	head_stack_a = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
	{
		(*stack_a)->prev = NULL;
	}
	if (*stack_b == NULL)
	{
		*stack_b = head_stack_a;
		head_stack_a->prev = NULL;
		head_stack_a->next = NULL;
	}
	else
	{
		temp = *stack_b;
		head_stack_a->next = temp;
		temp->prev = head_stack_a;
		*stack_b = head_stack_a;
	}
	main->count++;
}
