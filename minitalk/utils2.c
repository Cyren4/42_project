#include "minitalk.h"

int	power(int i, int pow)
{
	int	ret;

	ret = 1;
	while (pow > 0)
	{
		ret *= i;
		pow--;
	}
	return (ret);
}
