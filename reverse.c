/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:45:12 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/27 11:22:37 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_stack(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	*stack = (*stack)->prev;
	(*stack)->prev = NULL;
	ft_reset_index(*stack);
}

void	reverse_rotate_a(t_node **stack_a, int print)
{
	if (!stack_a || !*stack_a)
		return ;
	if (ft_size_stack(*stack_a) < 2)
		return ;
	ft_reverse_stack(stack_a);
	if (print)
		ft_putstr("rra\n");
}

void	reverse_rotate_b(t_node **stack_b, int print)
{
	if (!stack_b || !*stack_b)
		return ;
	if (ft_size_stack(*stack_b) < 2)
		return ;
	ft_reverse_stack(stack_b);
	if (print)
		ft_putstr("rrb\n");
}

void	reverse_rotate_r(t_node **stack_a, t_node **stack_b, int print)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	if (ft_size_stack(*stack_a) < 2 || ft_size_stack(*stack_b) < 2)
		return ;
	ft_reverse_stack(stack_a);
	ft_reverse_stack(stack_b);
	if (print)
		ft_putstr("rrr\n");
}
