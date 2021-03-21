/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_with_many_numbers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:09:52 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 20:01:56 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		push_all_numbers_stack_b(t_main *main, int divider)
{
	int		steps_from_head;
	int		steps_from_tail;

	initialize_elements(main, divider);
	while (!is_stack_empty(main->stack_a))
	{
		steps_from_head = count_step_from_head(main->stack_a, main->max_number);
		steps_from_tail = count_step_from_tail(main->stack_a, main->max_number);
		if (steps_from_head == NOT_FOUND && steps_from_tail == NOT_FOUND)
		{
			update_elements(main);
		}
		else if (steps_from_head < steps_from_tail)
		{
			rotate_stack_and_push_b(main, steps_from_head, FROM_HEAD);
		}
		else
		{
			rotate_stack_and_push_b(main, steps_from_tail, FROM_TAIL);
		}
		put_minimum_number_on_head(main);
	}
}

static void		push_all_numbers_stack_a(t_main *main)
{
	int		steps_from_head;
	int		steps_from_tail;

	while (!is_stack_empty(main->stack_b))
	{
		main->max_number = main->array[main->size - 1];
		steps_from_head = count_step_from_head_to_max(main);
		steps_from_tail = count_step_from_tail_to_max(main);
		if (steps_from_head < steps_from_tail)
		{
			rotate_stack_and_push_a(main, steps_from_head, FROM_HEAD);
		}
		else
		{
			rotate_stack_and_push_a(main, steps_from_tail, FROM_TAIL);
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
