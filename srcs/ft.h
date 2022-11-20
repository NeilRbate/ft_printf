/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:59:49 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/20 07:01:06 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s1);
void	ft_putstr_fd(const char *s1, int fd);
void	ft_putchar_fd(const char c, int fd);
