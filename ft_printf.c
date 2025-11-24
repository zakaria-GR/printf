#include "printf.h"
#include <stdio.h>
#include <unistd.h>

void ft_putchar(int c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void adressp(unsigned char *p)
{
	int	i;

	if (!p)
		return ;
	i = 0;
	while (p[i])
	{
		write(1, &p[i], 1);
		i++;
	}
}

void	ft_putnbru(unsigned int n)
{
	char c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, '-', 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbru(n / 10);
	}
	c = n % 10 + '0';
	write (1, &c, 1);
}
void	ft_putnbr(int n)
{
	char c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, '-', 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	c = n % 10 + '0';
	write (1, &c, 1);
}

void	ft_puthex(int n)
{
	char c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, '-', 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_puthex(n / 16);
	}
	c = n % 10 + '0';
	write (1, &c, 1);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			i++;
		}
		else if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				i++;
				int c = va_arg (args, int);
				ft_putchar(c);
			}
			if (format[i] == 'd' || format[i] == 'i')
			{
				i++;
				char d = va_arg (args, int);
				ft_putnbr(d);
			}
			if (format[i] == 's')
			{
				i++;
				char *s = va_arg (args, char *);
				ft_putstr(s);
			}
			if (format[i] == 'p')
			{
				i++;
				char *p = va_arg (args, void *);
				adressp(p);
			}
			if (format[i] == 'u')
			{
				i++;
				unsigned int u = va_arg (args, unsigned int);
				ft_putnbru(u);
			}
		}
	}
	va_end(args);
	return i;
}

int main()
{
	// unsigned int count = 100;
    // int negative_num = -5;

    // printf("Unsigned count: %u\n", count);
    // printf("Negative number as unsigned: %u\n", negative_num);

	// ft_printf("my Unsigned count: %u\n", count);
    // ft_printf("my Negative number as unsigned: %u\n", negative_num);

	int i = 343;
	int *p = &i;

	ft_printf("%p\n", p);
	printf("%p", p);
}