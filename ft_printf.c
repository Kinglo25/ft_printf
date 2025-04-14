/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:06:29 by lmajerus          #+#    #+#             */
/*   Updated: 2023/11/06 13:11:40 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	t_flags	flags;
	int		i;
	int		count;
	int		tmp;

	i = 0;
	count = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] != '%' && ++count)
			ft_putchar(input[i++]);
		else if (input[i++] == '%')
		{
			tmp = format_specification(input, &flags, args, &i);
			count += tmp;
			if (tmp == -1 || count > INT_MAX)
				return (-1);
		}
		if (g_write_err == -1)
			return (-1);
	}
	va_end(args);
	return (count);
}

int	format_specification(const char *input, t_flags *flags,
	va_list args, int *i)
{
	int		count;

	count = 0;
	fill_flags_struct(input, flags, args, i);
	if (input[*i] == 'c')
		count = printf_char(va_arg(args, int), flags);
	else if (input[*i] == 's')
		count = printf_str(va_arg(args, char *), flags);
	else if (input[*i] == 'p')
		count = printf_ptr(va_arg(args, unsigned long), flags);
	else if (input[*i] == 'd' || input[*i] == 'i')
		count = printf_dec_int(va_arg(args, int), flags);
	else if (input[*i] == 'u')
		count = printf_ui(va_arg(args, unsigned int), flags, 0);
	else if (input[*i] == 'x')
		count = printf_hexa(va_arg(args, unsigned int), flags, False, 0);
	else if (input[*i] == 'X')
		count = printf_hexa(va_arg(args, unsigned int), flags, True, 0);
	else if (input[*i] == '%')
		count = printf_percent(37, flags, 1);
	else
		return (-1);
	(*i)++;
	return (count);
}
