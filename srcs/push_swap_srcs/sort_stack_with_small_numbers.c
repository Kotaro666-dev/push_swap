/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_with_small_numbers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:54:19 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/23 13:31:44 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		make_stack_a_with_three_numbers(t_main *main)
{
	while (main->size > 3)
	{
		push_b_stdout(main);
		main->size--;
	}
}

static int		find_perfect_position(t_main *main, int target)
{
	t_stack	*current;
	t_stack	*head;
	int		position;

	current = main->stack_a->next;
	head = main->stack_a;
	position = 0;
	while (current != head)
	{
		if (target < current->value)
		{
			break ;
		}
		current = current->next;
		position++;
	}
	return (position);
}

static void		sort_stack_by_position(t_main *main, int position, int target)
{
	if (position == 0)
		;
	else if (position == main->size - 1)
		rotate_a_stdout(main);
	else if (position <= (main->size - 1) / 2)
	{
		while (!is_target_in_right_position(main, target))
		{
			swap_a_stdout(main);
			if (!is_stack_sorted(main->stack_a))
				rotate_a_stdout(main);
		}
		while (!is_stack_sorted(main->stack_a))
			reverse_rotate_a_stdout(main);
	}
	else
	{
		while (!is_target_in_right_position(main, target))
		{
			reverse_rotate_a_stdout(main);
			swap_a_stdout(main);
		}
		while (!is_stack_sorted(main->stack_a))
			rotate_a_stdout(main);
	}
}

void			push_max_and_min_number_to_stack_b(t_main *main)
{
	int	steps_from_head;
	int	steps_from_tail;

	steps_from_head = count_step_from_head_to_target(main, main->maximum);
	steps_from_tail = count_step_from_tail_to_target(main, main->maximum);
	if (steps_from_head < steps_from_tail)
	{
		rotate_stack_and_push_b(main, steps_from_head, FROM_HEAD);
	}
	else
	{
		rotate_stack_and_push_b(main, steps_from_tail, FROM_TAIL);
	}
	steps_from_head = count_step_from_head_to_target(main, main->minimum);
	steps_from_tail = count_step_from_tail_to_target(main, main->minimum);
	if (steps_from_head < steps_from_tail)
	{
		rotate_stack_and_push_b(main, steps_from_head, FROM_HEAD);
	}
	else
	{
		rotate_stack_and_push_b(main, steps_from_tail, FROM_TAIL);
	}
}

void			sort_stack_with_small_numbers(t_main *main)
{
	int target;
	int position;

	push_max_and_min_number_to_stack_b(main);
	make_stack_a_with_three_numbers(main);
	sort_stack_with_three_numbers(main);
	while (!is_stack_empty(main->stack_b))
	{
		push_a_stdout(main);
		main->size++;
		target = main->stack_a->value;
		if (target == main->minimum)
		{
			;
		}
		else if (target == main->maximum)
		{
			rotate_a_stdout(main);
		}
		else
		{
			position = find_perfect_position(main, target);
			sort_stack_by_position(main, position, target);
		}
	}
}
