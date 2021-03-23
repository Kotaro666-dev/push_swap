/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_with_three_numbers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:09:08 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/23 13:31:07 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		sort_stack_with_three_numbers(t_main *main)
{
	main->top = main->stack_a->value;
	main->middle = main->stack_a->next->value;
	main->bottom = main->stack_a->next->next->value;
	if (is_two_one_three(main))
	{
		swap_a_stdout(main);
	}
	else if (is_three_two_one(main))
	{
		swap_a_stdout(main);
		reverse_rotate_a_stdout(main);
	}
	else if (is_three_one_two(main))
	{
		rotate_a_stdout(main);
	}
	else if (is_one_three_two(main))
	{
		swap_a_stdout(main);
		rotate_a_stdout(main);
	}
	else if (is_two_three_one(main))
	{
		reverse_rotate_a_stdout(main);
	}
}
