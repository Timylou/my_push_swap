/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:38:06 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/19 17:38:12 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_node **stack)
{
	(*stack)->prev = (*stack)->next;
	(*stack)->index = 1;
	(*stack)->next = (*stack)->next->next;
	(*stack)->prev->next = (*stack);
	(*stack) = (*stack)->prev;
	(*stack)->index = 0;
	(*stack)->prev = NULL;
}

void	swap_a(t_node **stack)
{
	if (!stack || !*stack || ft_size_stack(*stack) < 2)
		return ;
	ft_swap(stack);
	ft_putstr("sa\n");
}

void	swap_b(t_node **stack)
{
	if (!stack || !*stack || ft_size_stack(*stack) < 2)
		return ;
	ft_swap(stack);
	ft_putstr("sb\n");
}

void	swap_s(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !*stack_a || ft_size_stack(*stack_a) < 2)
		return ;
	if (!stack_b || !*stack_b || ft_size_stack(*stack_b) < 2)
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr("ss\n");
}