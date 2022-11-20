/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:57:21 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/20 07:36:29 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	base_valid(char *str)
{
	int		len;
	int		i;
	int		j;
	char	stock;

	i = 0;
	j = 0;
	stock = 0;
	len = ft_strlen(str);
	if (len < 2)
		return (0);
	while (j > len)
	{
		stock = str[j];
		while (str[i])
		{
			if (stock == str[i] || stock == '+' || stock == '-')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (len);
}

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int		base_size;
	long	nbr2;

	nbr2 = nbr;
	base_size = base_valid(base);
	if (base_size > 1)
	{
		if (nbr < 0)
		{
			ft_putchar_fd('-', fd);
			nbr2 = -nbr2;
		}
		if (nbr2 < base_size)
			ft_putchar_fd(base[nbr2], fd);
		else
		{
			ft_putnbr_base_fd((nbr2 / base_size), base, fd);
			ft_putnbr_base_fd((nbr2 % base_size), base, fd);
		}
	}
}

void	ft_print(const char format, va_list args)
{
	if (format == '%')
		return (ft_putchar_fd('%', 1));
	else if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (format == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (format == 'u')
		return (ft_putnbr_fd(va_arg(args, unsigned int), 1));
	else if (format == 'x')
		return (ft_putnbr_base_fd(va_arg(args, int), "0123456789abcdef", 1));
	else if (format == 'X')
		return (ft_putnbr_base_fd(va_arg(args, int), "0123456789ABCDEF", 1));


}

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i++] == '%')
			ft_print(format[i], args);
		i++;
	}
	va_end(args);
	return (0);
}

int main()
{
	int i = 10;
	int a = 155;
	i = ft_printf("%X\n", a);
	ft_printf("%i", i);
	return (0);
}
