/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_numbers_to_stack_a_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:11:24 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 18:33:09 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			count_step_from_head_to_max(t_stack *stack, int max_number)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = stack;
	head = stack;
	step = 0;
	while (current->next != head)
	{
		if (current->value == max_number)
		{
			return (step);
		}
		current = current->next;
		step++;
	}
	if (current->value == max_number)
	{
		return (step);
	}
	return (NOT_FOUND);
}

int			count_step_from_tail_to_max(t_stack *stack, int max_number)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = stack;
	head = stack;
	step = 0;
	while (current->prev != head)
	{
		if (current->value == max_number)
		{
			return (step);
		}
		current = current->prev;
		step++;
	}
	if (current->value == max_number)
	{
		return (step);
	}
	return (NOT_FOUND);
}

void		push_a_from_head(t_main *main, int step_from_head)
{
	while (step_from_head != 0)
	{
		rotate_b_stdout(main);
		step_from_head--;
	}
	push_a_stdout(main);
}

void		push_a_from_tail(t_main *main, int step_from_tail)
{
	while (step_from_tail != 0)
	{
		reverse_rotate_b_stdout(main);
		step_from_tail--;
	}
	push_a_stdout(main);
}
