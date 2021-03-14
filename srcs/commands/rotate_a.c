/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:32 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/15 08:22:45 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ra
** rotate a - shift up all elements of stack a by 1.
** The first element becomes the last one.
*/

#include "commands.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack *head;
	t_stack *tail;
	int		temp_value;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		return ;
	}
	head = *stack_a;
	tail = *stack_a;
	while (tail->next)
	{
		tail = tail->next;
	}
	while (head != tail)
	{
		temp_value = head->value;
		head->value = tail->value;
		tail->value = temp_value;
		head = head->next;
		tail = tail->prev;
	}
}
