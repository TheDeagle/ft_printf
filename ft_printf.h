/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:20:50 by hben-bou          #+#    #+#             */
/*   Updated: 2022/11/02 06:20:52 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putcharr(int c);
int		ft_putchar(int c);
int		ft_printf_hexa(unsigned int nb, char format);
int		ft_printf_str(char *str);
int		ft_printf_pointer(unsigned long ptr);
int		ft_printf_unsigned(unsigned int nb);
int		ft_printf_number(int nb);
int		ft_printf_percent(void);
int		ft_printf(const char *str, ...);
void	ft_putstr(char *str);

#endif
