/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:04:09 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/17 07:49:07 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	// if (!is_stack_sorted(main.stack_a))
	// {
	// 	return (print_out_ko());
	// }
	// if (!is_stack_empty(main.stack_b))
	// {
	// 	return (print_out_ko());
	// }
	free_memory(&(main.stack_a), &(main.stack_b));
	return (print_out_ok());
}
