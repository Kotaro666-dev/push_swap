/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:58:17 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/27 16:54:21 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct			s_stack
{
	int					value;
	struct s_stack		*prev;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_option
{
	int					is_c;
	int					is_v;
}						t_option;

typedef struct			s_main
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	t_option			option;
	int					*array;
	int					len_array;
	int					size;
	int					top;
	int					middle;
	int					bottom;
	int					border;
	int					diff;
	int					max_number;
	int					maximum;
	int					minimum;
}						t_main;

#endif
