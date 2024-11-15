/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:27:02 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/15 19:33:14 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
}	t_node;

/* * * * * *
 *  HANDLE *
 *  ERRORS *
 * * * * * */

t_node	*ft_parse(int argc, char **argv);
void	ft_putstr(char str);
int		ft_atoi(char *str);

/* * * * * * * *
 *  STACK NODE *
 *  OPERATIONS *
 * * * * * * * */

int		ft_add_end_stack(t_node *stack, int data);
int		ft_size_stack(t_node *stack);
void	ft_free_stacks(t_node *stack_a, t_node *stack_b);
int		ft_is_sorted(t_node *stack);

void	ft_sort_small_stack(t_node *stack, int size_stack);
void	ft_sort_three_stack(t_node *stack);
void	ft_sort_stacks(t_node *stack_a, t_node *stack_b);

/* * * * * * * *
 *  PUSH_SWAP  *
 *  OPERATION  *
 * * * * * * * */

void	push_a(t_node *stack_a, t_node *stack b);
void	push_b(t_node *stack_a, t_node *stack b);

void	swap_a(t_node *stack_a);
void	swap_b(t_node *stack_b);
void	swap_s(t_node *stack_a, t_node *stack_b);

void	rotate_a(t_node *stack_a);
void	rotate_b(t_node *stack_b);
void	rotate_r(t_node *stack_a, t_node *stack_b);

void	reverse_rotate_a(t_node *stack_a);
void	reverse_rotate_b(t_node *stack_b);
void	reverse_rotate_r(t_node *stack_a, t_node *stack_b);
#endif
