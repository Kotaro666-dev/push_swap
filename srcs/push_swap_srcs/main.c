
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:04:09 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/20 08:58:33 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		sort_stack_by_size(t_main *main)
{
	if (main->size < 2)
	{
		return ;
	}
	else if (main->size == 2)
	{
		sort_stack_with_two_numbers(main);
	}
	else if (main->size == 3)
	{
		sort_stack_with_three_numbers(main);
	}
	else if (main->size <= 7)
	{
		sort_stack_with_small_numbers(main);
	}
	else if (main->size <= 100)
	{
		sort_stack_with_many_numbers(main, 5);
	}
	else
	{
		sort_stack_with_many_numbers(main, 11);
	}
}

int			main(int argc, char *argv[])
{
	t_main main;

	if (argc == 1)
	{
		return (0);
	}
	if (initialize_struct(&main, argc) == MALLOC_ERROR)
	{
		return (MALLOC_ERROR);
	}
	if (initialize_stack_a(&main, argv + 1) == ERROR)
	{
		return (print_out_error());
	}
	if (!is_every_number_unique(main.stack_a))
	{
		return (print_out_error());
	}
	sort_stack_by_size(&main);
	/// DEBUG BEGINS
	// print_out_stack(main.stack_a, main.stack_b);
	// print_out_count(&main);
	/// DEBUG ENDS
	free_memory(&(main.stack_a), &(main.stack_b));
	return (print_out_null_character());
}
