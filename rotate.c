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

void	ft_shift_up(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	*stack = (*stack)->prev;
	tmp = tmp->prev;
	tmp->next = NULL;
	ft_reset_index(*stack);
}

void	rotate_a(t_node **stack_a)
{
	if (!stack_a || !*stack_a)
		return ;
	if (ft_size_stack(*stack_a) < 2)
	   return ;	
	ft_shift_up(stack_a);
	ft_putstr("ra\n");
}

void	rotate_b(t_node **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	if (ft_size_stack(*stack_b) < 2)
	   return ;	
	ft_shift_up(stack_b);
	ft_putstr("rb\n");

}

void	rotate_r(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	if (ft_size_stack(*stack_a) < 2 || ft_size_stack(*stack_b) < 2)
		return ;
	ft_shift_up(stack_a);
	ft_shift_up(stack_b);
	ft_putstr("rr\n");
}

int	main()
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_add_end_stack(&stack_a, 3);
	ft_add_end_stack(&stack_a, 2);
	ft_add_end_stack(&stack_a, 1);

	rotate_a(&stack_a);
	ft_free_stacks(&stack_a, &stack_b);
}
