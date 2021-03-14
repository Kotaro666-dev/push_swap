/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_operate_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 07:43:33 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/15 08:49:19 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		operate_commands(char *line, t_checker *checker)
{
	if (!ft_strncmp(line, "sa", 2))
	{
		swap_a(&(checker->stack_a));
	}
	else if (!ft_strncmp(line, "sb", 2))
	{
		swap_b(&(checker->stack_b));
	}
	else if (!ft_strncmp(line, "ss", 2))
	{
		swap_a_and_b(checker->stack_a, checker->stack_b);
	}
	else if (!ft_strncmp(line, "pa", 2))
	{
		push_a(&(checker->stack_a), &(checker->stack_b));
	}
	else if (!ft_strncmp(line, "pb", 2))
	{
		push_b(&(checker->stack_a), &(checker->stack_b));
	}
	else if (!ft_strncmp(line, "ra", 2))
	{
		rotate_a(&(checker->stack_a));
	}
	else if (!ft_strncmp(line, "rb", 2))
	{
		rotate_b(&(checker->stack_b));
	}
	else if (!ft_strncmp(line, "rr", 2))
	{
		rotate_a_and_b(checker->stack_a, checker->stack_b);
	}
	else if (!ft_strncmp(line, "rra", 3))
	{

	}
	else if (!ft_strncmp(line, "rrb", 3))
	{

	}
	else if (!ft_strncmp(line, "rrr", 3))
	{

	}
	else
	{
		return (ERROR);
	}
	printf("---- stack_a -----\n");
	print_out_stack(checker->stack_a);
	printf("---- stack_b -----\n");
	print_out_stack(checker->stack_b);
	return (SUCCESS);
}

int		read_and_operate_commands(t_checker *checker)
{
	int		return_value;
	char	*line;
	char	*formatted_line;

	while (TRUE)
	{
		return_value = get_next_line(STDIN_FILENO, &line);
		if (return_value == GNL_EOF)
		{
			break ;
		}
		else if (return_value == GNL_ERROR)
		{
			return (ERROR);
		}
		formatted_line = ft_strtrim(line, " ");
		if (!formatted_line)
		{
			return (ERROR);
		}
		if (operate_commands(formatted_line, checker) == ERROR)
		{
			return (ERROR);
		}
		free(line);
		free(formatted_line);
	}
	line = NULL;
	formatted_line = NULL;
	return (SUCCESS);
}
