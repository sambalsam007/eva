/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samd-hoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:47:32 by samd-hoo          #+#    #+#             */
/*   Updated: 2024/07/19 15:49:05 by samd-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline_not_found(t_list *list)
{
	t_list	*current;
	int		i;

	current = list;
	while (current)
	{
		i = 0;
		while (current->str[i])
		{
			if (current->str[i] == '\n')
			{
				return (0);
			}
			i++;
		}
		current = current->next;
	}
	return (1);
}

int	length_til_newline(t_list *list)
{
	int		length;
	int		i;
	t_list	*current;

	length = 0;
	current = list;
	while (current)
	{
		i = 0;
		while (current->str[i])
		{
			if (current->str[i] == '\n')
			{
				return (length);
			}
			length++;
			i++;
		}
		current = current->next;
	}
	return (length);
}

void	free_memory(t_list **listRef, t_list *clean_node, char *buffer)
{
	t_list	*temp;

	temp = *listRef;
	while (*listRef)
	{
		temp = (*listRef)->next;
		free((*listRef)->str);
		free(*listRef);
		*listRef = temp;
	}
	*listRef = NULL;
	if (clean_node->str[0])
	{
		*listRef = clean_node;
	}
	else
	{
		free(buffer);
		free(clean_node);
	}
}
