/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_numbers_to_stack_a_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:11:24 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 20:03:07 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			count_step_from_head_to_max(t_main *main)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = main->stack_b;
	head = main->stack_b;
	step = 0;
	while (current->next != head)
	{
		if (current->value == main->max_number)
		{
			return (step);
		}
		current = current->next;
		step++;
	}
	if (current->value == main->max_number)
	{
		return (step);
	}
	return (NOT_FOUND);
}

int			count_step_from_tail_to_max(t_main *main)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = main->stack_b;
	head = main->stack_b;
	step = 0;
	while (current->prev != head)
	{
		if (current->value == main->max_number)
		{
			return (step);
		}
		current = current->prev;
		step++;
	}
	if (current->value == main->max_number)
	{
		return (step);
	}
	return (NOT_FOUND);
}

void		rotate_stack_and_push_a(t_main *main, int steps, int direction)
{
	while (steps != 0)
	{
		if (direction == FROM_HEAD)
		{
			rotate_b_stdout(main);
		}
		else if (direction == FROM_TAIL)
		{
			reverse_rotate_b_stdout(main);
		}
		steps--;
	}
	push_a_stdout(main);
}
