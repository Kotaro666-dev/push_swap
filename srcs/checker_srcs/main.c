/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:02:55 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/23 14:05:29 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(int argc, char *argv[])
{
	t_main main;

	if (argc == 1)
		return (0);
	if (initialize_struct(&main, argc) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	if (initialize_stack_a(&main, argv + 1) == ERROR)
		return (print_out_error(&main));
	if (!is_every_number_unique(main.stack_a))
		return (print_out_error(&main));
	if (read_and_operate_commands(&main) == ERROR)
	{
		return (print_out_error(&main));
	}
	if (!is_stack_sorted(main.stack_a))
	{
		return (print_out_ko(&main));
	}
	if (!is_stack_empty(main.stack_b))
	{
		return (print_out_ko(&main));
	}
	dispose_memory(&main);
	return (print_out_ok());
}
