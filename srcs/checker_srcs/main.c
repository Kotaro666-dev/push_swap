/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:02:55 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 22:52:06 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(int argc, char *argv[])
{
	t_main main;

	if (argc == 1)
	{
		return (0);
	}
	initialize_checker(&main);
	if (initialize_stack_a(&(main.stack_a), argv + 1) == ERROR)
	{
		return (print_out_error());
	}
	if (!is_every_number_unique(main.stack_a))
	{
		return (print_out_error());
	}
	if (read_and_operate_commands(&main) == ERROR)
	{
		return (print_out_error());
	}
	if (!is_stack_sorted(main.stack_a))
	{
		return (print_out_ko());
	}
	if (!is_stack_empty(main.stack_b))
	{
		return (print_out_ko());
	}
	free_memory(&(main.stack_a), &(main.stack_b));
	return (print_out_ok());
}
