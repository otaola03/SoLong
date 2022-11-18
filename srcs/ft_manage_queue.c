/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_queue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:44:34 by jperez            #+#    #+#             */
/*   Updated: 2022/11/18 17:52:05 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

t_queue	*ft_create_queue()
{
	t_queue *queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	queue->last = NULL;
	queue->first = NULL;
	return (queue);
}

t_node	*ft_create_node(int i, int j)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->i = i;
	node->j = j;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_enqueue(t_queue *queue, t_node *node)
{
	if (queue->first == NULL && queue->last == NULL)
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		node->next = queue->last;
		queue->last->prev = node;
		queue->last = node;
	}
}

void	ft_dequeue(t_queue *queue)
{
	t_node *aux;
	
	aux = queue->first;
	if (aux->prev)
	{
		queue->first = aux->prev;
		queue->first->next = NULL;
	}
	else
		queue->first = NULL;
	free(aux);
}

void	ft_free_queue(t_queue *queue)
{
	while (queue->last->next)
		ft_dequeue(queue);
	ft_dequeue(queue);
}
