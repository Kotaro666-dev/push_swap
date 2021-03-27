/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:20:34 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/27 15:43:49 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		sort_stack_by_size(t_main *main)
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
	else if (main->size <= 10)
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

int				main(int argc, char *argv[])
{
	t_main main;

	printf("BONUS");
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
		return (print_out_error(&main));
	}
	if (!is_every_number_unique(main.stack_a))
	{
		return (print_out_error(&main));
	}
	if (is_stack_sorted(main.stack_a))
	{
		return (print_out_null_character(&main));
	}
	sort_stack_by_size(&main);
	return (print_out_null_character(&main));
}
