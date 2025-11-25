#include "ft_printf.h"
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

void	ft_puthex(unsigned int n)
{
	char *c = "0123456789abcdef";

	if (n > 15)
	{
		ft_puthex(n / 16);
	}

	char cc = c[n % 16];
	write (1, &cc, 1);
}
void	ft_puthexup(unsigned int n)
{
	char *c = "0123456789ABCDEF";

	if (n > 15)
	{
		ft_puthexup(n / 16);
	}

	char cc = c[n % 16];
	write (1, &cc, 1);
}

void	adressp(uintptr_t p)
{
	if (!p)
		return ;
	char *c = "0123456789abcdef";

	//size_t n = (unsigned long)p;
	if (p > 15)
	{
		adressp(p / 16);
	}
	if (p < 10)
	{
		ft_putstr("0x");
	}
	char cc = c[p % 16];
	write (1, &cc, 1);
	
}

void	ft_putnbru(unsigned int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbru(n / 10);
	}
	c = n % 10 + '0';
	write (1, &c, 1);
}
void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
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
				ft_putchar(va_arg (args, int));
			}
			if (format[i] == 'd' || format[i] == 'i')
			{
				i++;
				ft_putnbr(va_arg (args, int));
			}
			if (format[i] == 's')
			{
				i++;
				ft_putstr(va_arg (args, char *));
			}
			if (format[i] == 'p')
			{
				i++;
				adressp(va_arg (args, uintptr_t));
			}
			if (format[i] == 'u')
			{
				i++;
				ft_putnbru(va_arg (args, unsigned int));
			}
			if (format[i] == 'X')
			{
				i++;
				ft_puthexup(va_arg (args, int));
			}
			if (format[i] == 'x')
			{
				i++;
				ft_puthex(va_arg (args, int));
			}
			if (format[i] == '%')
			{
				i++;
				ft_putchar('%');
			}
		}
	}
	va_end(args);
	return i;
}

int main()
{
	int i = 343;
	int *p = &i;

	ft_printf("%p %s %c %d rrrr %x %X %u %%\n", &p, "addsdcs", 'd', -2343415, -3323, -3323, -3434);
	printf("%p %s %c %d rrrr %x %X %u %%", &p, "addsdcs", 'd', -2343415, -3323, -3323, -3434);
}