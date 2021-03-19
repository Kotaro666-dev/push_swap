/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:36 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/19 13:58:32 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rb
** rotate b - shift up all elements of stack b by 1.
** The first element becomes the last one.
*/

#include "commands.h"

void	rotate_b(t_main *main)
{
	t_stack **stack_b;
	t_stack *head;

	stack_b = &(main->stack_b);
	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		return ;
	}
	head = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	while ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
	}
	head->next = NULL;
	head->prev = *stack_b;
	(*stack_b)->next = head;
	while ((*stack_b)->prev)
	{
		*stack_b = (*stack_b)->prev;
	}
	main->count++;
}
