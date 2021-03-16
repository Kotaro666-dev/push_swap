/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:04:09 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 22:39:20 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		initialize_checker(t_push_swap *push_swap)
{
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
}

int			main(int argc, char *argv[])
{
	t_push_swap push_swap;

	if (argc == 1)
	{
		return (0);
	}
	initialize_checker(&push_swap);
	if (initialize_stack_a(&(push_swap.stack_a), argv + 1) == ERROR)
	{
		return (print_out_error());
	}
	if (!is_every_number_unique(push_swap.stack_a))
	{
		return (print_out_error());
	}
	if (read_and_operate_commands_push_swap(&push_swap) == ERROR)
	{
		return (print_out_error());
	}
	if (!is_stack_sorted(push_swap.stack_a))
	{
		return (print_out_ko());
	}
	if (!is_stack_empty(push_swap.stack_b))
	{
		return (print_out_ko());
	}
	free_memory(&(push_swap.stack_a), &(push_swap.stack_b));
	return (print_out_ok());
}
