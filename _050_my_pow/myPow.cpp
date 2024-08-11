#include "myPow.h"

double myPow(double x, int n)
{
	double product = 1.0;
	return myTraversePow(x, n, product);
}

double myTraversePow(double x, int n, double product)
{
	if (n == 0)
	{
		return product;
	}

	if (x == 1.000)
	{
		return x;
	}

	if (n>0)
	{
		product *= x;
		myTraversePow(x, n - 1, product);
	}
	
	if (n<0)
	{
		product /= x;
		myTraversePow(x, n + 1, product);
	}
}