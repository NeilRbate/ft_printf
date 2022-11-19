/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:57:21 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/19 11:46:00 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft.h"

void	ft_print(const char format, va_list args)
{
	va_start(args, format);
	if (format == '%')
		return (ft_putchar_fd(%));
	else if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (format == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if ((format == 'd' || format[i] == 'i')
		return (ft_putnbr(va_arg(args, int), 1));


}

int	ft_printf(const char *format, ...)
{
	va_list args;
	while (format[i])
	{
		ft_print(format[i], args);	
	}
	j += i;
	va_end(args);
	return (j);
}

#include <stdio.h>

int main()
{
	int i;
	char *test = "Salut !";
	char tes = 'A';
	i = ft_printf("%s, ceci est une phrase, -> %c\n", test, tes);
	printf("%d", i);
	return (0);
}
