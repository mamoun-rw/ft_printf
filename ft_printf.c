/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalruwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:27:17 by maalruwa          #+#    #+#             */
/*   Updated: 2026/10/14 11:01:51 by maalruwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	tselect_format(va_list list, const char *fmt)
{
	int	cou;

	cou = 0;
	if (*fmt == '%' && (*(fmt + 1) == 'd' || *(fmt + 1) == 'i'))
		cou = ft_itoa(va_arg(list, int));
	else if (*fmt == '%' && *(fmt + 1) == 'u')
		cou = ft_uitoa(va_arg(list, unsigned int));
	else if (*fmt == '%' && *(fmt + 1) == '%')
	{
		write(1, "%", 1);
		cou++;
	}
	return (cou);
}

static int	select_format(va_list list, const char *fmt)
{
	int		cou;
	char	c;

	cou = 0;
	if ((*fmt == '%' && *(fmt + 1) == 'c'))
	{
		c = (char)va_arg(list, int);
		write(1, &c, 1);
		cou++;
	}
	else if (*fmt == '%' && *(fmt + 1) == 's')
		cou = strprn(va_arg(list, char *));
	else if (*fmt == '%' && *(fmt + 1) == 'p')
		cou = ft_print_hex((unsigned long)va_arg(list, void *), 0, 1);
	else if (*fmt == '%' && *(fmt + 1) == 'x')
		cou = ft_print_hex(va_arg(list, unsigned int), 0, 0);
	else if (*fmt == '%' && *(fmt + 1) == 'X')
		cou = ft_print_hex(va_arg(list, unsigned int), 1, 0);
	else
		cou = tselect_format(list, fmt);
	return (cou);
}

static int	process_format(const char **fmt, va_list list)
{
	int	cou;

	cou = select_format(list, *fmt);
	if (cou == -1)
		return (-1);
	(*fmt) += 2;
	return (cou);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		list;
	int			counter;
	int			cou;

	if (!fmt)
		return (-1);
	va_start(list, fmt);
	counter = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			cou = process_format(&fmt, list);
		else
			cou = (write(1, fmt++, 1));
		if (cou == -1)
		{
			va_end(list);
			return (-1);
		}
		counter += cou;
	}
	va_end(list);
	return (counter);
}
