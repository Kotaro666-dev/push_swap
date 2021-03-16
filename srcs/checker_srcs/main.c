/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:02:55 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 22:30:23 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		initialize_checker(t_checker *checker)
{
	checker->stack_a = NULL;
	checker->stack_b = NULL;
}

int		main(int argc, char *argv[])
{
	t_checker checker;

	if (argc == 1)
	{
		return (0);
	}
	initialize_checker(&checker);
	if (initialize_stack_a(&(checker.stack_a), argv + 1) == ERROR)
	{
		return (print_out_error());
	}
	if (!is_every_number_unique(checker.stack_a))
	{
		return (print_out_error());
	}
	if (read_and_operate_commands(&checker) == ERROR)
	{
		return (print_out_error());
	}
	if (!is_stack_sorted(checker.stack_a))
	{
		return (print_out_ko());
	}
	if (!is_stack_empty(checker.stack_b))
	{
		return (print_out_ko());
	}
	free_memory(&(checker.stack_a), &(checker.stack_b));
	return (print_out_ok());
}
