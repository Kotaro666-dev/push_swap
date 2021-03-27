/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_max_and_min_number_stack_b.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:49:16 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/27 13:49:56 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		push_max_number_to_stack_b(t_main *main)
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
}

void		push_min_number_to_stack_b(t_main *main)
{
	int	steps_from_head;
	int	steps_from_tail;

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
