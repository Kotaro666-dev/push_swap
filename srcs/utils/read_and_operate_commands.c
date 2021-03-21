/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_operate_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 07:43:33 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 14:25:06 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		operate_commands(char *line, t_main *main)
{
	if (!ft_strcmp(line, "sa"))
		swap_a(main);
	else if (!ft_strcmp(line, "sb"))
		swap_b(main);
	else if (!ft_strcmp(line, "ss"))
		swap_a_and_b(main);
	else if (!ft_strcmp(line, "pa"))
		push_a(main);
	else if (!ft_strcmp(line, "pb"))
		push_b(main);
	else if (!ft_strcmp(line, "ra"))
		rotate_a(main);
	else if (!ft_strcmp(line, "rb"))
		rotate_b(main);
	else if (!ft_strcmp(line, "rr"))
		rotate_a_and_b(main);
	else if (!ft_strcmp(line, "rra"))
		reverse_rotate_a(main);
	else if (!ft_strcmp(line, "rrb"))
		reverse_rotate_b(main);
	else if (!ft_strcmp(line, "rrr"))
		reverse_rotate_a_and_b(main);
	else
		return (ERROR);
	return (SUCCESS);
}

int		read_and_operate_commands(t_main *main)
{
	int		return_value;
	char	*line;
	char	*formatted_line;

	while (TRUE)
	{
		return_value = get_next_line(STDIN_FILENO, &line);
		if (return_value == GNL_EOF)
		{
			free(line);
			break ;
		}
		else if (return_value == GNL_ERROR)
			return (ERROR);
		formatted_line = ft_strtrim(line, " ");
		if (!formatted_line)
			return (ERROR);
		if (operate_commands(formatted_line, main) == ERROR)
			return (ERROR);
		free(line);
		free(formatted_line);
	}
	line = NULL;
	formatted_line = NULL;
	return (SUCCESS);
}
