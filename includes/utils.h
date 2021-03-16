/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:44:25 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/17 07:48:00 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "constant.h"
# include "struct.h"
# include "get_next_line.h"
# include "commands.h"

/*
** PRINT_OUT.C
*/

int			print_out_ok(void);
int			print_out_ko(void);
int			print_out_error(void);

/*
** UTILITIES.C
*/

int			is_arg_numeric(char *arg);
int			is_stack_empty(t_stack *stack);
int			is_stack_sorted(t_stack *stack);
int			is_every_number_unique(t_stack *stack);

/*
**	READ_AND_OPERATE_COMMANDS.C
*/

int			read_and_operate_commands(t_main *main);


/*
** FREE_MEMORY.C
*/

void		free_stack(t_stack **stack);
void		free_memory(t_stack **stack_a, t_stack **stack_b);

/*
** INITIALIZE.C
*/

void		initialize_struct(t_main *main);
int			store_value_in_stack_a(t_stack **stack_a, int num);
int			initialize_stack_a(t_main *main, char **argv);

#endif
