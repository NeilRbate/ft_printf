/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:57:21 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/21 10:46:18 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int	ft_write(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
	return (i);
}

unsigned int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	unsigned long long	base_size;
	unsigned int		ret;
	unsigned long long	nbr2;

	nbr2 = nbr;
	ret = 0;
	base_size = ft_strlen(base);
	if (base_size > 1)
	{
		if (nbr2 < base_size)
			ret += write(1, base + nbr2, 1);
		else
		{
			ft_putnbr_base((nbr2 / base_size), base);
			ft_putnbr_base((nbr2 % base_size), base);
		}
	}
		return (ret);
}

unsigned int	ft_print(const char format, va_list args)
{
	long	i;

	if (format == '%')
		return (write(1, "%", 1));
	else if (format == 'c')
		return (write(1, &format, 1));
	else if (format == 's')
		return (ft_write(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
	{
		i = va_arg(args, int);
		if (i < 0)
		{
			i *= -1;
			return (write(1, "-", 1) + (ft_putnbr_base(i, "0123456789")));
		}
		return (ft_putnbr_base(i, "0123456789"));
	}
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF"));
	else if (format == 'p')
		return (write(1, "0x", 2) + ft_putnbr_base(va_arg(args, unsigned long long), "0123456789abcdef"));
	else
		return(write(1, &format, 1));

	return (0);

}

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			 j += ft_print(format[++i], args);
			 i++;
		}
		else
		{
			j += write(1, format + i, 1);
			i++;
		}
	}
	va_end(args);
	return (j);
}

int main()
{
	int *a;
	int b = -15;
	a = &b;
	int i;
	int j;
	i = ft_printf("Salut -> %p je suis cool b -> %i\n", a, b);
	j = printf("Salut -> %p je suis cool b -> %i\n", a, b);
	ft_printf("%i\n", i);
	ft_printf("%i\n", j);
	return (0);
}
