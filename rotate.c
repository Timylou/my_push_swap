/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:14:56 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/23 12:14:59 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_index(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

static void	ft_shift_up(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	*stack = tmp;
	(*stack)->prev = NULL;
	ft_reset_index(*stack);
}

void	rotate_a(t_node **stack_a, int print)
{
	if (!stack_a || !*stack_a)
		return ;
	if (ft_size_stack(*stack_a) < 2)
		return ;
	ft_shift_up(stack_a);
	if (print)
		ft_putstr("ra\n");
}

void	rotate_b(t_node **stack_b, int print)
{
	if (!stack_b || !*stack_b)
		return ;
	if (ft_size_stack(*stack_b) < 2)
		return ;
	ft_shift_up(stack_b);
	if (print)
		ft_putstr("rb\n");
}

void	rotate_r(t_node **stack_a, t_node **stack_b, int print)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	if (ft_size_stack(*stack_a) < 2 || ft_size_stack(*stack_b) < 2)
		return ;
	ft_shift_up(stack_a);
	ft_shift_up(stack_b);
	if (print)
		ft_putstr("rr\n");
}
