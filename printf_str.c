/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:32:13 by lmajerus          #+#    #+#             */
/*   Updated: 2023/10/20 15:23:53 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_str(char *str, t_flags *flags)
{
	int		count;
	int		str_len;

	count = 0;
	if (flags->width > (INT_MAX - 1))
		return (-1);
	if (str == NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	if (flags->precision < 0)
		flags->bool_precision = False;
	if (flags->bool_precision)
	{
		if (flags->precision < str_len)
			flags->width -= flags->precision;
		else
			flags->width -= str_len;
	}
	else
		flags->width -= str_len;
	if (flags->bool_minus)
		count += char_width(str, flags);
	else
		count += width_char(str, flags);
	return (count);
}

int	char_width(char *str, t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->bool_precision)
		while (*str && flags->precision-- > 0 && ++count)
			ft_putchar(*str++);
	else
	{
		while (*str)
		{
			ft_putchar(*str++);
			count++;
		}
	}
	while (flags->width-- > 0)
	{
		if (flags->bool_zeros == True)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count++;
	}
	return (count);
}

int	width_char(char *str, t_flags *flags)
{
	int		count;

	count = 0;
	while (flags->width-- > 0)
	{
		if (flags->bool_zeros == True)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count++;
	}
	if (flags->bool_precision)
		while (*str && flags->precision-- > 0 && ++count)
			ft_putchar(*str++);
	else
	{
		while (*str)
		{
			ft_putchar(*str++);
			count++;
		}
	}
	return (count);
}
