/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:47:45 by lmajerus          #+#    #+#             */
/*   Updated: 2023/10/20 15:14:51 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putnbr_hexa(unsigned long n, t_bool capital)
{
	char	*hexa;
	char	*cap_hexa;

	hexa = "0123456789abcdef";
	cap_hexa = "0123456789ABCDEF";
	if (n > 15)
		ft_putnbr_hexa(n / 16, capital);
	if (capital)
		ft_putchar(cap_hexa[n % 16]);
	else
		ft_putchar(hexa[n % 16]);
}

int	find_hexa_len(unsigned long x)
{
	if (x < 16ul)
		return (1);
	return (1 + find_hexa_len(x / 16));
}

int	find_ui_len(unsigned int x)
{
	if (x < 10)
		return (1);
	return (1 + find_ui_len(x / 10));
}
