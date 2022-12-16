/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:23:42 by hben-bou          #+#    #+#             */
/*   Updated: 2022/11/02 07:23:42 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ptr_len(uintptr_t ptr)
{
	int	counter;

	counter = 0;
	while (ptr)
	{
		ptr /= 16;
		counter++;
	}
	return (counter);
}

void	put_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		put_ptr(ptr / 16);
		put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putcharr(ptr + 48);
		else
			ft_putcharr(ptr - 10 + 'a');
	}
}

int	ft_printf_pointer(unsigned long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (!ptr)
	{
		ft_putcharr('0');
		len++;
	}
	else
	{
		put_ptr(ptr);
		len += ptr_len(ptr);
	}
	return (len);
}
