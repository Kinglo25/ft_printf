/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:05:58 by lmajerus          #+#    #+#             */
/*   Updated: 2023/11/01 09:43:15 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_hexa(unsigned long hexa, t_flags *flags, t_bool capital, int count)
{
	int		hexa_len;

	if (flags->width > (INT_MAX - 1) || flags->precision > (INT_MAX - 1))
		return (-1);
	hexa_len = find_hexa_len(hexa);
	if (hexa == 0 && flags->bool_precision && !flags->precision)
	{
		while (flags->width-- && ++count)
			ft_putchar(' ');
		return (count);
	}
	if (hexa_len > flags->precision)
		flags->width -= hexa_len;
	else
		flags->width -= flags->precision;
	if (flags->precision < 0)
		return (if_flag_precision_neg_hexa(hexa, flags, capital) + hexa_len);
	if (flags->bool_precision == True)
		flags->bool_zeros = False;
	if (flags->bool_minus == True)
		count += precision_width_hexa(hexa, flags, hexa_len, capital);
	else if (flags->bool_minus == False)
		count += width_precision_hexa(hexa, flags, hexa_len, capital);
	return (count + hexa_len);
}

int	precision_width_hexa(unsigned long hexa, t_flags *flags,
		int hexa_len, t_bool capital)
{
	int		count;

	count = 0;
	while (flags->precision-- > hexa_len)
	{
		ft_putchar('0');
		count++;
	}
	ft_putnbr_hexa(hexa, capital);
	while (flags->width-- > 0)
	{
		ft_putchar(' ');
		count++;
	}
	return (count);
}

int	width_precision_hexa(unsigned long hexa, t_flags *flags,
		int hexa_len, t_bool capital)
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
	while (flags->precision-- > hexa_len)
	{
		ft_putchar('0');
		count++;
	}
	ft_putnbr_hexa(hexa, capital);
	return (count);
}

int	if_flag_precision_neg_hexa(unsigned long hexa, t_flags *flags,
		t_bool capital)
{
	int		count;

	count = 0;
	if (flags->bool_minus == False && flags->bool_zeros == False)
		while (flags->width-- > 0 && ++count)
			ft_putchar(' ');
	if (flags->bool_zeros)
	{
		while (flags->width-- > 0 && ++count)
			ft_putchar('0');
		ft_putnbr_hexa(hexa, capital);
	}
	if (!flags->bool_zeros)
	{
		ft_putnbr_hexa(hexa, capital);
		while (flags->width-- > 0 && ++count)
			ft_putchar(' ');
	}
	return (count);
}
