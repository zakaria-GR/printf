#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


int		ft_printf(const char *format, ...);
void	ft_putnbr(int n);
void	putchar(char c);


#endif