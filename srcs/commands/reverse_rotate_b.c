/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:15 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/19 19:50:18 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rrb
** reverse rotate b - shift down all elements of stack b by 1.
** The last element becomes the first one.
*/

#include "commands.h"

void	reverse_rotate_b(t_main *main)
{
	t_stack **stack_b;

	stack_b = &(main->stack_b);
	if (*stack_b == NULL)
	{
		return ;
	}
	*stack_b = (*stack_b)->prev;
	main->count++;
}

// void	reverse_rotate_b(t_main *main)
// {
// 	t_stack **stack_b;
// 	t_stack *tail;

// 	stack_b = &(main->stack_b);
// 	if (*stack_b == NULL || (*stack_b)->next == NULL)
// 	{
// 		return ;
// 	}
// 	while ((*stack_b)->next)
// 	{
// 		*stack_b = (*stack_b)->next;
// 	}
// 	tail = *stack_b;
// 	*stack_b = (*stack_b)->prev;
// 	(*stack_b)->next = NULL;
// 	while ((*stack_b)->prev)
// 	{
// 		*stack_b = (*stack_b)->prev;
// 	}
// 	tail->prev = NULL;
// 	tail->next = *stack_b;
// 	(*stack_b)->prev = tail;
// 	*stack_b = (*stack_b)->prev;
// 	main->count++;
// }
