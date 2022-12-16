/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 05:30:41 by hben-bou          #+#    #+#             */
/*   Updated: 2022/11/06 01:48:36 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	hex_len(unsigned int nb)
{
	int	counter;

	counter = 0;
	while (nb)
	{
		nb /= 16;
		counter++;
	}
	return (counter);
}

void	put_hex(unsigned int nb, char format)
{
	if (nb >= 16)
	{
		put_hex(nb / 16, format);
		put_hex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putcharr(nb + 48);
		else
		{
			if (format == 'x')
				ft_putcharr(nb - 10 + 'a');
			if (format == 'X')
				ft_putcharr(nb - 10 + 'A');
		}
	}
}

int	ft_printf_hexa(unsigned int nb, char format)
{
	int	len;

	len = hex_len(nb);
	if (!nb)
		return (write(1, "0", 1));
	else
		put_hex(nb, format);
	return (len);
}
