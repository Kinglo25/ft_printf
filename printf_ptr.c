/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:55:00 by lmajerus          #+#    #+#             */
/*   Updated: 2023/10/20 15:22:22 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_ptr(unsigned long ptr, t_flags *flags)
{
	int		count;
	int		hexa_len;

	count = 0;
	if (flags->width > (INT_MAX - 1) || flags->precision > (INT_MAX - 1))
		return (-1);
	hexa_len = find_hexa_len(ptr) + 2;
	if (hexa_len > flags->precision)
		flags->width -= hexa_len;
	else
		flags->width -= (flags->precision + 2);
	if (!ptr)
		return (if_null_ptr(flags, ptr, hexa_len));
	if (flags->bool_minus)
		count += if_flag_minus(ptr, flags, hexa_len);
	else
		count += if_no_flag_minus(ptr, flags, hexa_len);
	return (count + hexa_len);
}

int	if_null_ptr(t_flags *flags, unsigned long ptr, int hexa_len)
{
	int		count;

	count = 0;
	if (flags->bool_minus)
		return (if_flag_minus(ptr, flags, hexa_len) + 2);
	if (flags->bool_precision)
		flags->width++;
	while (flags->width-- > 0 && ++count)
		ft_putchar(' ');
	ft_putchar('0');
	ft_putchar('x');
	while (flags->precision-- > 0 && ++count)
		ft_putchar('0');
	if (!flags->bool_precision && ++count)
		ft_putchar('0');
	return (count + 2);
}

int	if_flag_minus(unsigned long ptr, t_flags *flags, int hexa_len)
{
	int		count;

	count = 0;
	ft_putchar('0');
	ft_putchar('x');
	while (flags->precision-- > (hexa_len - 2) && ++count)
		ft_putchar('0');
	if (!flags->bool_precision && !ptr && ++count)
		ft_putnbr_hexa(ptr, False);
	else if (ptr)
		ft_putnbr_hexa(ptr, False);
	else
		flags->width++;
	while (flags->width-- > 0 && ++count)
		ft_putchar(' ');
	return (count);
}

int	if_no_flag_minus(unsigned long ptr, t_flags *flags, int hexa_len)
{
	int		count;

	count = 0;
	while (flags->width-- > 0 && ++count)
		ft_putchar(' ');
	ft_putchar('0');
	ft_putchar('x');
	while (flags->precision-- > (hexa_len - 2) && ++count)
		ft_putchar('0');
	ft_putnbr_hexa(ptr, False);
	return (count);
}
