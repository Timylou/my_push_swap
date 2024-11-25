/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:16:37 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/15 14:17:25 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small_stack(t_node **stack, int size_stack)
{
	int	current_data;
	int	next_data;

	if (size_stack < 2)
		return ;
	current_data = (*stack)->data;
	next_data = (*stack)->next->data;
	if (current_data > next_data)
		swap_a(stack);
	return ;
}

void	ft_sort_three_stack(t_node **stack)
{
	int		i;
	t_node	*temp;
	t_node	*max;

	max = *stack;
	temp = *stack;
	i = 0;
	while (i < 2)
	{
		temp = temp->next;
		if (temp->data > max->data)
			max = temp;
		i++;
	}
	if (max->index == 0)
		rotate_a(stack);
	else if (max->index == 1)
		reverse_rotate_a(stack);
	if (!ft_is_sorted(*stack))
		swap_a(stack);
	return ;
}
