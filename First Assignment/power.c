#include "myMath.h"
#define e 2.71828

double power (double x, int y)
{
 double ans = 1;
 int i;
 for (i = 0; i < y; i++)
 {
    ans *= x;
 }
 return ans;
}

double Exponent(int x)
{
    return power(e,x);
}