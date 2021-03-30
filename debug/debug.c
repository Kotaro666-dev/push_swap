/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:44:50 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 13:00:18 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_out_stack_a(t_stack **current_a)
{
	if (*current_a)
	{
		printf("%d  ", (*current_a)->value);
		*current_a = (*current_a)->next;
	}
	else
	{
		printf("   ");
	}
}

void	print_out_stack_b(t_stack **current_b)
{
	if (*current_b)
	{
		printf("%d", (*current_b)->value);
		*current_b = (*current_b)->next;
	}
	else
	{
		printf(" ");
	}
}

void	print_out_stack(t_main *main)
{
	t_stack *current_a;
	t_stack *current_b;
	t_stack *head_a;
	t_stack *head_b;

	if (main->option.is_v == FALSE)
	{
		return ;
	}
	current_a = main->stack_a;
	current_b = main->stack_b;
	head_a = main->stack_a;
	head_b = main->stack_b;
	printf("_  _\n");
	while (current_a || current_b)
	{
		print_out_stack_a(&current_a);
		print_out_stack_b(&current_b);
		if (current_a == head_a)
		{
			current_a = NULL;
		}
		if (current_b == head_b)
		{
			current_b = NULL;
		}
		printf("\n");
	}
	printf("_  _\n");
	printf("a  b\n");
}

void	print_out_stack_and_clear_screen(t_main *main)
{
	if (main->option.is_v == FALSE)
	{
		return ;
	}
	print_out_stack(main);
	usleep(0.15 * 1000000);
	printf(CLEAR_SCREEN);
}
