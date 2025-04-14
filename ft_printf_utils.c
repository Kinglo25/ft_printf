/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:04:46 by lmajerus          #+#    #+#             */
/*   Updated: 2023/11/06 13:00:53 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *input, int *i)
{
	int	ans;

	ans = 0;
	while (input[*i] >= '0' && input[*i] <= '9')
		ans = (ans * 10) + (input[(*i)++] - '0');
	return (ans);
}

void	ft_putnbr(long n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

void	ft_putchar(char c)
{
	if (write(1, &c, 1) < 0)
		g_write_err = -1;
}

int	find_d_len(long x)
{
	if (x < 10)
		return (1);
	return (1 + find_d_len(x / 10));
}

void	ft_putnbr_ui(unsigned int n)
{
	if (n > 9)
		ft_putnbr_ui(n / 10);
	ft_putchar(n % 10 + 48);
}
