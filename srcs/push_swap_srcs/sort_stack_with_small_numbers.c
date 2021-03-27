/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_with_small_numbers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:54:19 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/27 14:09:02 by kkamashi         ###   ########.fr       */
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
