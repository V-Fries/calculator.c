/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:22:27 by vfries            #+#    #+#             */
/*   Updated: 2023/01/09 02:39:01 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "ft_linked_list.h"
# include <stdbool.h>
# include <stdint.h>

# define PARENTHES_ERROR "Parenthes parsing failed\n"

// operators.c
bool	is_an_operator(char *args);
void	add_operator(t_list **tokens, t_list **operators, char operator);

// parenthes.c
uint8_t	is_parenthes(char *args);
void	open_parenthes(t_list **tokens, t_list **operators);
void	close_parenthes(t_list **tokens, t_list **operators);

// parse_arguments.c
t_list	*parse_arguments(char *args);

#endif
