/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_with_many_numbers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:09:52 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 18:32:56 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		push_all_numbers_stack_b(t_main *main, int divider)
{
	int		step_from_head;
	int		step_from_tail;

	set_main_members(main, divider);
	while (!is_stack_empty(main->stack_a))
	{
		step_from_head = count_step_from_head(main->stack_a, main->max_number);
		step_from_tail = count_step_from_tail(main->stack_a, main->max_number);
		if (step_from_head == NOT_FOUND && step_from_tail == NOT_FOUND)
		{
			update_main_members(main);
		}
		else if (step_from_head < step_from_tail)
		{
			push_b_from_top(main, step_from_head);
		}
		else
		{
			push_b_from_tail(main, step_from_tail);
		}
		put_minimum_number_on_head(main);
	}
}

static void		push_all_numbers_stack_a(t_main *main)
{
	int		max_number;
	int		step_from_head;
	int		step_from_tail;

	while (!is_stack_empty(main->stack_b))
	{
		max_number = main->array[main->size - 1];
		step_from_head = count_step_from_head_to_max(main->stack_b, max_number);
		step_from_tail = count_step_from_tail_to_max(main->stack_b, max_number);
		if (step_from_head < step_from_tail)
		{
			push_a_from_head(main, step_from_head);
		}
		else
		{
			push_a_from_tail(main, step_from_tail);
		}
		main->size--;
	}
}

void			sort_stack_with_many_numbers(t_main *main, int divider)
{
	ft_qsort(main->array, 0, main->size - 1);
	push_all_numbers_stack_b(main, divider);
	push_all_numbers_stack_a(main);
}
