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

int	ft_puthex(unsigned int n)
{
	char *c = "0123456789abcdef";
	int count;

	count = 0;
	if (n > 15)
	{
		count += ft_puthex(n / 16);
	}

	char cc = c[n % 16];
	count += write (1, &cc, 1);
	return (count);
}
int	ft_puthexup(unsigned int n)
{
	char *c = "0123456789ABCDEF";
	int count;

	count = 0;
	if (n > 15)
	{
		count += ft_puthexup(n / 16);
	}

	char cc = c[n % 16];
	count += write (1, &cc, 1);
	return (count);
}

int	adressp(uintptr_t p)
{
	char *c = "0123456789abcdef";
	int count;

	count = 0;
	if (p > 15)
	{
		count += adressp(p / 16);
	}
	char cc = c[p % 16];
	count += write (1, &cc, 1);
	return (count);
}

int	ft_putnbru(unsigned int n)
{
	char	c;
	int count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbru(n / 10);
	}
	c = n % 10 + '0';
	count += write (1, &c, 1);
	return (count);
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
		count += ft_putnbr(n / 10);
	}
	c = n % 10 + '0';
	count += write (1, &c, 1);
	return (count);
}
int formatp(va_list args)
{
	int count;
	void *str;

	count = 0;
	str = va_arg (args, void *);
	count += write(1, "0x", 2);
	if (!str)
		count += ft_putchar('0');
	else
		count += adressp((uintptr_t)str);
	return(count);
}

int ifformat(const char format, va_list args)
{
	int count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg (args, int));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg (args, int));
	else if (format == 's')
		count += ft_putstr(va_arg (args, char *));
	else if (format == 'p')
		count += formatp(args);
	else if (format == 'u')
		count += ft_putnbru(va_arg (args, unsigned int));
	else if (format == 'X')
		count += ft_puthexup(va_arg (args, unsigned int));
	else if (format == 'x')
		count += ft_puthex(va_arg (args, unsigned int));
	else if (format == '%')
		count += ft_putchar('%');
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
		if (format[i] == '%')
		{
			i++;
			count += ifformat(format[i], args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

int main()
{
	int i = 343;
	int *p = &i;

	//ft_printf("%p %s %c %d rrrr %x %X %u %%\n", p, "addsdcs", 'd', -2343415, -3323, -3323, -3434);
	//printf("%p %s %c %d rrrr %x %X %u %%", p, "addsdcs", 'd', -2343415, -3323, -3323, -3434);
	printf("%r%\n");
	ft_printf("%r%");
}