/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_with_three_numbers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:09:08 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 14:00:29 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		sort_stack_with_three_numbers(t_main *main)
{
	main->top = main->stack_a->value;
	main->middle = main->stack_a->next->value;
	main->bottom = main->stack_a->next->next->value;
	if (main->top > main->middle && main->top < main->bottom)
	{
		swap_a_stdout(main);
	}
	else if (main->top > main->middle && main->middle > main->bottom)
	{
		swap_a_stdout(main);
		reverse_rotate_a_stdout(main);
	}
	else if (main->top > main->middle && main->middle < main->bottom)
	{
		rotate_a_stdout(main);
	}
	else if (main->top < main->middle && main->top < main->bottom && main->middle > main->bottom)
	{
		swap_a_stdout(main);
		rotate_a_stdout(main);
	}
	else if (main->top < main->middle && main->top > main->bottom && main->middle > main->bottom)
	{
		reverse_rotate_a_stdout(main);
	}
}
