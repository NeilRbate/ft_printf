/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:57:21 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/21 14:07:48 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

unsigned int	ft_putnbr_base(unsigned long long nbr, char *base, int *ret)
{
	unsigned long long	nbr2;
	unsigned long long	i;

	nbr2 = nbr;
	i = 0;
	while (base[i])
		i++;
	if (i > 1)
	{
		if (nbr2 < i)
			return(*ret += write(1, base + nbr2, 1));
		else
		{
			ft_putnbr_base((nbr2 / i), base, ret);
			ft_putnbr_base((nbr2 % i), base, ret);
		}
	}
		return (*ret);
}

unsigned int	ft_print(const char format, va_list args)
{
	int		i;
	int 	j;

	i = 0;
	j = 0;
	if (format == 'c')
		return (write(1, &format, 1));
	else if (format == 's')
		return (ft_write(va_arg(args, char *)));
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789", &i));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef", &i));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", &i));
	else if (format == 'p')
		return ((write(1, "0x", 2) + ft_putnbr_base(va_arg(args, unsigned long long), "0123456789abcdef", &i)));
	else if (format == 'd' || format == 'i')
	{
		j = va_arg(args, int);
		if (j < 0)
		{
			j *= -1;
			return ((write(1, "-", 1) + (ft_putnbr_base(j, "0123456789", &i))));
		}
		return (ft_putnbr_base(j, "0123456789", &i));
	}
	return(write(1, "%", 1) + write(1, &format, 1));
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
		if (format[i] == '%' && format[i + 1] != '%')
		{
			 j += ft_print(format[++i], args);
			 i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			j += write(1, "%", 1);
			i += 2;
		}
		else
			j += write(1, format + i++, 1);
	}
	va_end(args);
	return (j);
}

/*int main()
{
	int *a;
	int b = 5000000;
	a = &b;
	int i;
	int j;
	i = ft_printf("Salut %% -> %i p -> %p \n", b, a);
	j = printf("Salut %% -> %i p -> %p \n", b, a);
	j = printf("\nSalut -> %p je suis cool b -> %i\n", a, b);
	printf("%i\n", i);
	printf("%i\n", j);
	return (0);
}*/
