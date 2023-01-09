/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:35:52 by vfries            #+#    #+#             */
/*   Updated: 2023/01/09 01:35:35 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

enum e_type
{
	NUMBER = 0,
	OPERATOR = 1,
};

enum e_operators
{
	PLUS = 0,
	MINUS = 1,
	MULT = 2,
	DIV = 3,
	OPEN_PARENTHESES = 4,
	CLOSE_PARENTHESES = 5,
};

enum e_operators_priorities
{
	PLUS = 0,
	MINUS = 0,
	MULT = 1,
	DIV = 1,
	OPEN_PARENTHESES = 255,
	CLOSE_PARENTHESES = 255,
};

typedef struct s_token
{
	int		data;
	e_type	type;
}	t_token;

#endif