/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:33:40 by minpark           #+#    #+#             */
/*   Updated: 2024/10/10 21:25:34 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_char(int i);
int	ft_print_decimal(int n);
int	ft_print_hex(unsigned int num, char src);
int	ft_print_str(char *str);
int	ft_print_unsigned_decimal(unsigned int n);
int	ft_print_voidptr(void *str);

#endif
