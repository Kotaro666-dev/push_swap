/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:04:09 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/19 14:02:34 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		sort_stack_a_by_size_is_two(t_main *main)
{
	t_stack **stack_a;

	stack_a = &(main->stack_a);
	if ((*stack_a)->value < (*stack_a)->next->value)
	{
		return ;
	}
	swap_a(main);
}

void		sort_stack_a_by_size_is_three(t_main *main)
{
	t_stack **stack_a;

	stack_a = &(main->stack_a);
	main->top = (*stack_a)->value;
	main->middle = (*stack_a)->next->value;
	main->bottom = (*stack_a)->next->next->value;
	if (main->top > main->middle && main->top < main->bottom)
	{
		swap_a(main);
	}
	else if (main->top > main->middle && main->middle > main->bottom)
	{
		swap_a(main);
		reverse_rotate_a(main);
	}
	else if (main->top > main->middle && main->middle < main->bottom)
	{
		rotate_a(main);
	}
	else if (main->top < main->middle && main->top < main->bottom && main->middle > main->bottom)
	{
		swap_a(main);
		rotate_a(main);
	}
	else if (main->top < main->middle && main->top > main->bottom && main->middle > main->bottom)
	{
		reverse_rotate_a(main);
	}
}

void		sort_stack_a_by_size(t_main *main)
{
	if (main->size < 2)
		return ;
	else if (main->size == 2)
	{
		sort_stack_a_by_size_is_two(main);
	}
	else if (main->size == 3)
	{
		sort_stack_a_by_size_is_three(main);
	}
	else if (main->size <= 5)
	{

	}
	else
	{

	}
}


int			main(int argc, char *argv[])
{
	t_main main;

	if (argc == 1)
	{
		return (0);
	}
	initialize_struct(&main);
	if (initialize_stack_a(&main, argv + 1) == ERROR)
	{
		return (print_out_error());
	}
	if (!is_every_number_unique(main.stack_a))
	{
		return (print_out_error());
	}
	// SORT
	sort_stack_a_by_size(&main);
	// if (!is_stack_sorted(main.stack_a))
	// {
	// 	return (print_out_ko());
	// }
	// if (!is_stack_empty(main.stack_b))
	// {
	// 	return (print_out_ko());
	// }
	print_out_stack(main.stack_a, main.stack_b);
	print_out_count(&main);
	free_memory(&(main.stack_a), &(main.stack_b));
	return (print_out_ok());
}
