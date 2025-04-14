/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:59:11 by lmajerus          #+#    #+#             */
/*   Updated: 2023/10/20 15:12:16 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags_struct(t_flags *flags)
{
	flags->bool_minus = False;
	flags->bool_precision = False;
	flags->bool_width = False;
	flags->bool_zeros = False;
	flags->precision = 0;
	flags->width = 0;
	return ;
}

void	width_precision_flags2(const char *input, t_flags *flags,
		va_list args, int *i)
{
	flags->bool_precision = True;
	if (input[*i] == '*')
	{
		flags->precision = va_arg(args, int);
		(*i)++;
	}
	else if (input[*i] >= '0' && input[*i] <= '9')
		flags->precision = ft_atoi(input, i);
}

void	width_precision_flags(const char *input, t_flags *flags,
		va_list args, int *i)
{
	if (input[*i] == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width == 0)
			flags->bool_zeros = True;
		if (flags->width < 0)
		{
			flags->bool_minus = True;
			flags->width *= -1;
		}
		(*i)++;
	}
	else if (input[*i] >= '0' && input[*i] <= '9')
	{
		flags->bool_width = True;
		flags->width = ft_atoi(input, i);
	}
	if (input[*i] == '.' && (*i)++)
	{
		width_precision_flags2(input, flags, args, i);
	}
}

void	fill_flags_struct(const char *input, t_flags *flags,
		va_list args, int *i)
{
	init_flags_struct(flags);
	while (input[*i] == '0' || input[*i] == '-')
	{
		if (input[*i] == '0')
			flags->bool_zeros = True;
		else if (input[*i] == '-')
			flags->bool_minus = True;
		(*i)++;
	}
	width_precision_flags(input, flags, args, i);
	if (flags->bool_minus == True)
		flags->bool_zeros = False;
	return ;
}
