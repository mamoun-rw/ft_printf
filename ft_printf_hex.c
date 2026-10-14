/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalruwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:41:14 by maalruwa          #+#    #+#             */
/*   Updated: 2026/10/14 09:36:29 by maalruwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_length(const unsigned long num)
{
	unsigned long	tmp;
	int				digits;

	tmp = num;
	digits = 0;
	if (tmp == 0)
		return (1);
	while (tmp > 0)
	{
		tmp /= 16;
		digits++;
	}
	return (digits);
}

static char	*to_hex_string(unsigned long num, int uppercase, int len)
{
	char	*hex;
	char	*str;
	int		i;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = len;
	while (i > 0)
	{
		str[i - 1] = hex[num % 16];
		num /= 16;
		i--;
	}
	return (str);
}

int	ft_print_hex(unsigned long num, int uppercase, int is_pointer)
{
	int		len;
	char	*str;
	int		count;

	if (is_pointer && num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = hex_length(num);
	str = to_hex_string(num, uppercase, len);
	if (!str)
		return (-1);
	count = len;
	if (is_pointer)
	{
		write(1, "0x", 2);
		count += 2;
	}
	write(1, str, len);
	free(str);
	return (count);
}
