/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_titoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalruwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:20:03 by maalruwa          #+#    #+#             */
/*   Updated: 2026/10/14 10:24:21 by maalruwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strprn(char *str)
{
	int		num;
	char	*ptr;

	ptr = str;
	num = 0;
	if (!ptr)
		ptr = "(null)";
	while (*ptr)
	{
		write(1, ptr, 1);
		ptr++;
		num++;
	}
	return (num);
}

static int	ul_num(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	l_num(int n)
{
	int	i;

	if (n <= 0)
		i = 1;
	else
		i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_uitoa(unsigned int n)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	num;

	num = n;
	i = ul_num(n);
	ptr = malloc(i + 1);
	if (!ptr)
		return (-1);
	ptr[i] = '\0';
	if (num == 0)
		ptr[0] = '0';
	while (num > 0)
	{
		ptr[--i] = (num % 10) + '0';
		num /= 10;
	}
	i = strprn(ptr);
	free(ptr);
	return (i);
}

int	ft_itoa(int n)
{
	char			*ptr;
	int				i;
	unsigned int	num;

	i = l_num(n);
	ptr = malloc(i + 1);
	if (!ptr)
		return (-1);
	ptr[i] = '\0';
	if (n == 0)
		ptr[0] = '0';
	num = n;
	if (n < 0)
	{
		ptr[0] = '-';
		num = -n;
	}
	while (num > 0)
	{
		ptr[--i] = (num % 10) + '0';
		num /= 10;
	}
	i = strprn(ptr);
	free(ptr);
	return (i);
}
