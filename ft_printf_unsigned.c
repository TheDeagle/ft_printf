/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:10:46 by hben-bou          #+#    #+#             */
/*   Updated: 2022/11/06 01:49:28 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	uns_len(unsigned int nb)
{
	int	counter;

	counter = 0;
	while (nb)
	{
		nb /= 10;
		counter++;
	}
	return (counter);
}

void	put_uns(unsigned int nb)
{
	unsigned long	nbr;

	nbr = nb;
	if (nb > 9)
	{
		put_uns(nbr / 10);
		put_uns(nbr % 10);
	}
	else
		ft_putcharr(nbr + 48);
}

int	ft_printf_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (!nb)
		return (write(1, "0", 1));
	else
	{
		put_uns(nb);
		len += uns_len(nb);
	}
	return (len);
}
