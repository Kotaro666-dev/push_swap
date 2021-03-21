/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:58:17 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 14:46:04 by kkamashi         ###   ########.fr       */
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

typedef struct			s_main
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	int					*array;
	int					size;
	int					count;
	int					top;
	int					middle;
	int					bottom;
}						t_main;

#endif
