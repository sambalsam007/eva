/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samd-hoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:48:29 by samd-hoo          #+#    #+#             */
/*   Updated: 2024/07/19 16:05:34 by samd-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif 

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	clean_list(t_list **listRef);
char	*extract_line(t_list *list);
void	reading(t_list **listRef, int fd );
void	append(t_list **listRef, char *buffer);

int		newline_not_found(t_list *list);
int		length_til_newline(t_list *list);
void	free_memory(t_list **listRef, t_list *clean_node, char *buffer);

#endif
