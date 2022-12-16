/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:06:27 by hben-bou          #+#    #+#             */
/*   Updated: 2022/11/02 09:06:28 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	num_len(int nb)
{
	long int	counter;

	counter = 0;
	if (nb <= 0)
		counter++;
	while (nb)
	{
		nb /= 10;
		counter++;
	}
	return (counter);
}

void	ft_putnbr(int nb)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		ft_putcharr('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n % 10 + 48);
}

int	ft_printf_number(int nb)
{
	int	len;

	len = 0;
	ft_putnbr(nb);
	len += num_len(nb);
	return (len);
}
