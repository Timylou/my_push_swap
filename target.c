/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:40:32 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/26 16:28:37 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_closest_bigger(int data, t_node *dest, t_node *max)
{
	t_node	*closest_bigger;

	closest_bigger = max;
	while (dest)
	{
		if (dest->data > data && dest->data < closest_bigger->data
			&& dest->data < max->data)
			closest_bigger = dest;
		dest = dest->next;
	}
	return (closest_bigger);
}

t_node	*ft_find_closest_smaller(int data, t_node *dest, t_node *min)
{
	t_node	*closest_smaller;

	closest_smaller = min;
	while (dest)
	{
		if (dest->data < data && dest->data > closest_smaller->data
			&& dest->data > min->data)
			closest_smaller = dest;
		dest = dest->next;
	}
	return (closest_smaller);
}

t_node	*ft_find_max(t_node *stack)
{
	t_node	*max;

	max = stack;
	while (stack)
	{
		if (stack->data > max->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_node	*ft_find_min(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->data < min->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	ft_set_target(t_node *src, t_node *dest, int smaller)
{
	t_node	*min;
	t_node	*max;

	min = ft_find_min(dest);
	max = ft_find_max(dest);
	while (src)
	{
		if (smaller)
		{
			if (src->data < min->data)
				src->target = max;
			else
				src->target = ft_find_closest_smaller(src->data, dest, min);
		}
		else
		{
			if (src->data > max->data)
				src->target = min;
			else
				src->target = ft_find_closest_bigger(src->data, dest, max);
		}
		src = src->next;
	}
}
