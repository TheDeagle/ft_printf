/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:06:41 by hben-bou          #+#    #+#             */
/*   Updated: 2022/11/02 08:06:42 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	formats(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	if (format == 's')
		len += ft_printf_str(va_arg(args, char *));
	if (format == 'p')
		len += ft_printf_pointer(va_arg(args, unsigned long));
	if (format == 'd' || format == 'i')
		len += ft_printf_number(va_arg(args, int));
	if (format == 'u')
		len += ft_printf_unsigned(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		len += ft_printf_hexa(va_arg(args, unsigned int), format);
	if (format == '%')
		len += ft_printf_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
