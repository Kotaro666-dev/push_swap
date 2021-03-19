/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:32 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/19 13:57:55 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ra
** rotate a - shift up all elements of stack a by 1.
** The first element becomes the last one.
*/

#include "commands.h"

void	rotate_a(t_main *main)
{
	t_stack **stack_a;
	t_stack *head;

	stack_a = &(main->stack_a);
	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		return ;
	}
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
	}
	head->next = NULL;
	head->prev = *stack_a;
	(*stack_a)->next = head;
	while ((*stack_a)->prev)
	{
		*stack_a = (*stack_a)->prev;
	}
	main->count++;
}
