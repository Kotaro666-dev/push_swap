/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:58:05 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/23 11:58:37 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int				count_step_from_head_to_target(t_main *main, int target)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = main->stack_a;
	head = main->stack_a;
	step = 0;
	while (current->next != head)
	{
		if (current->value == target)
		{
			return (step);
		}
		current = current->next;
		step++;
	}
	if (current->value == target)
	{
		return (step);
	}
	return (NOT_FOUND);
}

int				count_step_from_tail_to_target(t_main *main, int target)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = main->stack_a;
	head = main->stack_a;
	step = 0;
	while (current->prev != head)
	{
		if (current->value == target)
		{
			return (step);
		}
		current = current->prev;
		step++;
	}
	if (current->value == target)
	{
		return (step);
	}
	return (NOT_FOUND);
}
