/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_with_many_numbers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:09:52 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 14:01:33 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		push_all_numbers_stack_b(t_main *main, int divider)
{
	int		border;
	int		diff;
	int		maximum;
	int		step_from_top;
	int		step_from_tail;

	border = main->size / divider;
	diff = main->size / divider;
	maximum = main->array[border - 1];
	while (!is_stack_empty(main->stack_a))
	{
		step_from_top = count_step_from_top(main->stack_a, maximum);
		step_from_tail = count_step_from_tail(main->stack_a, maximum);
		if (step_from_top == NOT_FOUND && step_from_tail == NOT_FOUND)
		{
			border += diff;
			if (border > main->size)
			{
				border = main->size;
			}
			maximum = main->array[border - 1];
		}
		else if (step_from_top < step_from_tail)
		{
			while (step_from_top != 0)
			{
				rotate_a_stdout(main);
				step_from_top--;
			}
			push_b_stdout(main);
		}
		else
		{
			while (step_from_tail != 0)
			{
				reverse_rotate_a_stdout(main);
				step_from_tail--;
			}
			push_b_stdout(main);
		}
		put_minimum_number_on_top(main);
	}
}

static void		push_all_numbers_stack_a(t_main *main)
{
	int		maximum;
	int		step_from_top;
	int		step_from_tail;

	while (!is_stack_empty(main->stack_b))
	{
		maximum = main->array[main->size - 1];
		step_from_top = count_step_to_maximum_from_head(main->stack_b, maximum);
		step_from_tail = count_step_to_maximum_from_tail(main->stack_b, maximum);
		if (step_from_top < step_from_tail)
		{
			while (step_from_top != 0)
			{
				rotate_b_stdout(main);
				step_from_top--;
			}
			push_a_stdout(main);
		}
		else
		{
			while (step_from_tail != 0)
			{
				reverse_rotate_b_stdout(main);
				step_from_tail--;
			}
			push_a_stdout(main);
		}
		main->size--;
	}
}

void		sort_stack_with_many_numbers(t_main *main, int divider)
{
	ft_qsort(main->array, 0, main->size - 1);
	push_all_numbers_stack_b(main, divider);
	push_all_numbers_stack_a(main);
}
