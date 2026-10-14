/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalruwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:42:02 by maalruwa          #+#    #+#             */
/*   Updated: 2026/10/14 11:02:15 by maalruwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_uitoa(unsigned int n);
int	ft_itoa(int n);
int	ft_print_hex(unsigned long num, int uppercase, int is_pointer);
int	strprn(char *str);

#endif