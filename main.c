#include "printf.h"
#include <stdio.h>

#include <stdio.h>
void	ft_puthex(int n)
{
	char c;

	if (n > 15)
	{
		ft_puthex(n / 16);
	}
    if (n >= 0 && n <= 9) 
	{
        c = n % 16 + '0'; 
		write (1, &c, 1);
    }
	// if (n == 10)
	// 	c = 'A';
	// if (n == 11)
	// 	c = 'B';
	// if (n == 12)
	// 	c = 'C';
	// if (n == 13)
	// 	c = 'D';
	// if (n == 14)
	// 	c = 'E';
	// if (n == 15)
	// 	c = 'F';
	if (n >= 10 && n <= 15)
	{
        c = (char)(n - 10 + 'A'); 
		write (1, &c, 1);
    }
	c = n % 16 + '0'; 
	write (1, &c, 1);

	}

int main() {
    // unsigned int count = 100;
    // int negative_num = -6;

    // printf("Unsigned count: %u\n", count);
    // printf("Negative number as unsigned: %u\n", negative_num); // This will show a large positive number due to two's complement interpretation
    // return 0;
	int i = 4779;
	ft_puthex(i);
	printf("\n");
	printf("%X", 4779);
}
