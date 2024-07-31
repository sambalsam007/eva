/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samd-hoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:30:45 by samd-hoo          #+#    #+#             */
/*   Updated: 2024/07/31 15:00:36 by samd-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

# include <stdio.h> 

/* TESTING STUFF
# define TEST 0
# define t_write_number 0
# define t_write_unsigned_int 0
# define t_write_hexa_lower 0
# define t_write_hexa_upper 0
# define t_write_address 0
# define t_length_printf 0

# define test_char 0
# define test_string 0
# define test_int 0
# define test_percentage 0
# define test_unsigned 0
# define test_hexa 1
# define test_address 1
# define test_invalid 0
*/

# define test_all 0

int	ft_printf(const char *string, ...);
int	write_char(char temp);
int	write_str(char *temp);
int	write_number(int temp);
int	write_unsigned_int(unsigned int temp);
int	write_hexa_lower(unsigned int temp);
int	write_hexa_upper(unsigned int temp);
int	write_address(int *temp);

#endif
