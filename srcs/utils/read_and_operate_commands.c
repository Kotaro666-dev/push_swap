/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_operate_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 07:43:33 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 15:52:26 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		operate_commands(char *line, t_checker *checker)
{
	if (!ft_strcmp(line, "sa"))
	{
		swap_a(&(checker->stack_a));
	}
	else if (!ft_strcmp(line, "sb"))
	{
		swap_b(&(checker->stack_b));
	}
	else if (!ft_strcmp(line, "ss"))
	{
		swap_a_and_b(checker);
	}
	else if (!ft_strcmp(line, "pa"))
	{
		push_a(&(checker->stack_a), &(checker->stack_b));
	}
	else if (!ft_strcmp(line, "pb"))
	{
		push_b(&(checker->stack_a), &(checker->stack_b));
	}
	else if (!ft_strcmp(line, "ra"))
	{
		rotate_a(&(checker->stack_a));
	}
	else if (!ft_strcmp(line, "rb"))
	{
		rotate_b(&(checker->stack_b));
	}
	else if (!ft_strcmp(line, "rr"))
	{
		rotate_a_and_b(checker);
	}
	else if (!ft_strcmp(line, "rra"))
	{
		reverse_rotate_a(&(checker->stack_a));
	}
	else if (!ft_strcmp(line, "rrb"))
	{
		reverse_rotate_b(&(checker->stack_b));
	}
	else if (!ft_strcmp(line, "rrr"))
	{
		reverse_rotate_a_and_b(checker);
	}
	else
	{
		return (ERROR);
	}
	print_out_stack(checker->stack_a, checker->stack_b);
	return (SUCCESS);
}

int		read_and_operate_commands(t_checker *checker)
{
	int		return_value;
	char	*line;
	char	*formatted_line;

	print_out_stack(checker->stack_a, checker->stack_b);
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
