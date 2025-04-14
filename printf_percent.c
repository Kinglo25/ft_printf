/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:10:58 by lmajerus          #+#    #+#             */
/*   Updated: 2023/11/01 09:39:01 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_percent(char c, t_flags *flags, int count)
{
	if (flags->bool_minus)
	{
		ft_putchar(c);
		while (flags->width-- > 1 && ++count)
		{
			if (flags->bool_zeros)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
	else
	{
		while (flags->width-- > 1 && ++count)
		{
			if (flags->bool_zeros)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putchar(c);
	}
	return (count);
}
