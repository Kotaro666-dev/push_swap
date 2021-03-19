/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:17 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/19 14:01:25 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rra
** reverse rotate a - shift down all elements of stack a by 1.
** The last element becomes the first one.
*/

#include "commands.h"

void	reverse_rotate_a(t_main *main)
{
	t_stack **stack_a;
	t_stack *tail;

	stack_a = &(main->stack_a);
	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		return ;
	}
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
	}
	tail = *stack_a;
	*stack_a = (*stack_a)->prev;
	(*stack_a)->next = NULL;
	while ((*stack_a)->prev)
	{
		*stack_a = (*stack_a)->prev;
	}
	tail->prev = NULL;
	tail->next = *stack_a;
	(*stack_a)->prev = tail;
	*stack_a = (*stack_a)->prev;
	main->count++;
}
