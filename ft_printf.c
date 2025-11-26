#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int count;

	count = 0;
	if (!s)
	{
		count += write (1, "(null)", 6);
		return (count);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		count ++;
		i++;
	}
	return (count);
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
	char *c = "0123456789abcdef";

	if (p > 15)
	{
		adressp(p / 16);
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
int	ft_putnbr(int n)
{
	char	c;
	int count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	c = n % 10 + '0';
	count += write (1, &c, 1);
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count += ft_putchar(format[i]);
			i++;
		}
		else if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				i++;
				count += ft_putchar(va_arg (args, int));
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				i++;
				count += ft_putnbr(va_arg (args, int));
			}
			else if (format[i] == 's')
			{
				i++;
				count += ft_putstr(va_arg (args, char *));
			}
			else if (format[i] == 'p')
			{
				i++;
				void *str = va_arg (args, void *);
				count += ft_putstr("0x");
				if (!str)
					ft_putchar('0');
				else
					adressp((uintptr_t)str);
			}
			else if (format[i] == 'u')
			{
				i++;
				ft_putnbru(va_arg (args, unsigned int));
			}
			else if (format[i] == 'X')
			{
				i++;
				ft_puthexup(va_arg (args, unsigned int));
			}
			else if (format[i] == 'x')
			{
				i++;
				ft_puthex(va_arg (args, unsigned int));
			}
			else if (format[i] == '%')
			{
				i++;
				count += ft_putchar('%');
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

	ft_printf("%p %s %c %d rrrr %x %X %u %%\n", p, "addsdcs", 'd', -2343415, -3323, -3323, -3434);
	printf("%p %s %c %d rrrr %x %X %u %%", p, "addsdcs", 'd', -2343415, -3323, -3323, -3434);
}