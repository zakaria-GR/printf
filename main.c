//#include "ft_printf.h"
#include <stdio.h>
#include <stdint.h>

#include <stdio.h>
void	ft_puthex(uintptr_t p)
{
	char *c = "0123456789abcdef";

	//size_t n = (unsigned long)p;
	if (p > 15)
	{
		ft_puthex(p / 16);
	}
	if (p < 10)
	{
		ft_putstr("0x");
	}
	char cc = c[p % 16];
	write (1, &cc, 1);
	
}

int main() {
    // unsigned int count = 100;
    // int negative_num = -6;

    // printf("Unsigned count: %u\n", count);
    // printf("Negative number as unsigned: %u\n", negative_num); // This will show a large positive number due to two's complement interpretation
    // return 0;
	int i = 343;
	int *p = &i;

	ft_puthex(&p);
	printf("\n");
	printf("%p", &p);
}
