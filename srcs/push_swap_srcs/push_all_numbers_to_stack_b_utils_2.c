/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_numbers_to_stack_b_utils_2.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:53:06 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/23 11:46:22 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			update_elements(t_main *main)
{
	main->border += main->diff;
	if (main->border > main->size)
	{
		main->border = main->size;
	}
	main->max_number = main->array[main->border - 1];
}

void			initialize_elements(t_main *main, int divider)
{
	main->border = main->size / divider;
	main->diff = main->size / divider;
	main->max_number = main->array[main->border - 1];
}

void			rotate_stack_and_push_b(t_main *main, int steps, int direction)
{
	while (steps != 0)
	{
		if (direction == FROM_HEAD)
		{
			rotate_a_stdout(main);
		}
		else if (direction == FROM_TAIL)
		{
			reverse_rotate_a_stdout(main);
		}
		steps--;
	}
	push_b_stdout(main);
	main->size--;
}
