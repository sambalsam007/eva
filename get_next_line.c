/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samd-hoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:47:37 by samd-hoo          #+#    #+#             */
/*   Updated: 2024/07/19 15:50:49 by samd-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	append(t_list **listRef, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (*listRef == NULL)
		*listRef = new_node;
	else
	{
		last_node = *listRef;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	new_node->str = buffer;
	new_node->next = NULL;
}

void	reading(t_list **listRef, int fd )
{
	ssize_t	bytes_read;
	char	*buffer;

	while (newline_not_found(*listRef))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
		{
			return ;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		append(listRef, buffer);
	}
}

char	*extract_line(t_list *list)
{
	char	*buffer;
	int		i;
	int		k;
	t_list	*current;

	buffer = (char *)malloc(length_til_newline(list) + 1);
	k = 0;
	current = list;
	while (current)
	{
		i = 0;
		while (current->str[i])
		{
			buffer[k] = current->str[i];
			if (current->str[i++] == '\n')
			{
				buffer[++k] = '\0';
				return (buffer);
			}
			k++;
		}
		current = current->next;
	}
	buffer[k] = '\0';
	return (buffer);
}

void	clean_list(t_list **listRef)
{
	t_list	*clean_node;
	t_list	*last_node;
	char	*buffer;
	int		i;
	int		k;

	if (*listRef == NULL)
		return ;
	clean_node = malloc(sizeof(t_list));
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return ;
	last_node = *listRef;
	while (last_node->next)
		last_node = last_node->next;
	i = 0;
	while (last_node->str[i] != '\n' && last_node->str[i])
		i++;
	k = 0;
	while (last_node->str[i] != '\0' && last_node->str[i++])
		buffer[k++] = last_node->str[i];
	buffer[k] = '\0';
	clean_node->str = buffer;
	clean_node->next = NULL;
	free_memory(listRef, clean_node, buffer);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	reading(&list, fd);
	if (list == NULL )
		return (NULL);
	line = extract_line(list);
	clean_list(&list);
	return (line);
}
