/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:33:28 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/26 14:03:39 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_init_stack()
{
	t_node *new_stack;

	new_stack = malloc(sizeof(t_node));
	if (!new_stack)
		return (NULL);
	new_stack->data = -1;
	new_stack->index = -1;
	new_stack->push_cost = -1;
	new_stack->prev = NULL;
	new_stack->next = NULL;
	new_stack->target = NULL;
	return (new_stack);
}

int	ft_add_end_stack(t_node **stack, int data)
{
	t_node	*new_stack;
	t_node	*temp;

	new_stack = ft_init_stack();
	if (!new_stack)
		return (0);
	new_stack->data = data;
	if (!*stack)
	{
		*stack = new_stack;
		new_stack->index = 0;
		return (1);
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_stack;
	new_stack->prev = temp;
	new_stack->index = temp->index + 1;
	return (1);
}

int	ft_size_stack(t_node *stack)
{
	int	i;

	 i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_free_stacks(t_node **stack_a, t_node **stack_b)
{
	t_node *temp;

	if (stack_a)
	{
		while (*stack_a)
		{
			temp = *stack_a;
			*stack_a = (*stack_a)->next;
			free(temp);
			temp = NULL;
		}
	}
	if (stack_b)
	{
		while (*stack_b)
		{
			temp = *stack_b;
			*stack_b = (*stack_b)->next;
			free(temp);
			temp = NULL;
		}
	}
}

int	ft_is_sorted(t_node *stack)
{
	int	prev_data;

	if (!stack)
		return (0);
	prev_data = stack->data;
	stack = stack->next;
	while (stack)
	{
		if (prev_data > stack->data)
			return (0);
		prev_data = stack->data;
		stack = stack->next;
	}
	return (1);
}
