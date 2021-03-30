/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:44:50 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 17:08:01 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		add_space(int num)
{
	int digit;
	int count;

	digit = 0;
	if (num == 0)
	{
		digit = 1;
	}
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	count = 8 - digit;
	while (count)
	{
		write(STDOUT_FILENO, " ", 1);
		count--;
	}
}

static void		print_out_stack_a(t_stack **current_a)
{
	write(STDOUT_FILENO, "|", 1);
	if (*current_a)
	{
		add_space((*current_a)->value);
		ft_putnbr_fd((*current_a)->value, STDOUT_FILENO);
		*current_a = (*current_a)->next;
	}
	else
	{
		ft_putstr_fd("        ", STDOUT_FILENO);
	}
}

static void		print_out_stack_b(t_stack **current_b)
{
	if (*current_b)
	{
		add_space((*current_b)->value);
		ft_putnbr_fd((*current_b)->value, STDOUT_FILENO);
		*current_b = (*current_b)->next;
	}
	else
	{
		ft_putstr_fd("        ", STDOUT_FILENO);
	}
	write(STDOUT_FILENO, "|", 1);
}

void			print_out_stack(t_main *main)
{
	t_stack *current_a;
	t_stack *current_b;
	t_stack *head_a;
	t_stack *head_b;

	if (main->option.is_v == FALSE)
		return ;
	current_a = main->stack_a;
	current_b = main->stack_b;
	head_a = main->stack_a;
	head_b = main->stack_b;
	ft_putendl_fd("---------|---------", STDOUT_FILENO);
	while (current_a || current_b)
	{
		print_out_stack_a(&current_a);
		write(STDOUT_FILENO, "|", 1);
		print_out_stack_b(&current_b);
		if (current_a == head_a)
			current_a = NULL;
		if (current_b == head_b)
			current_b = NULL;
		write(STDOUT_FILENO, "\n", 1);
	}
	ft_putendl_fd("----A----|----B----", STDOUT_FILENO);
}

void			print_out_stack_and_clear_screen(t_main *main)
{
	if (main->option.is_v == FALSE)
	{
		return ;
	}
	ft_putstr_fd(CLEAR_SCREEN, STDOUT_FILENO);
	print_out_stack(main);
	usleep(SLEEP_TIME);
}
