/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_numbers_to_stack_a_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:11:24 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/20 21:26:40 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			count_step_to_maximum_from_head(t_stack *stack, int maximum)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = stack;
	head = stack;
	step = 0;
	while (current->next != head)
	{
		if (current->value == maximum)
		{
			return (step);
		}
		current = current->next;
		step++;
	}
	if (current->value == maximum)
	{
		return (step);
	}
	return (NOT_FOUND);
}

int			count_step_to_maximum_from_tail(t_stack *stack, int maximum)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = stack;
	head = stack;
	step = 0;
	while (current->prev != head)
	{
		if (current->value == maximum)
		{
			return (step);
		}
		current = current->prev;
		step++;
	}
	if (current->value == maximum)
	{
		return (step);
	}
	return (NOT_FOUND);
}
