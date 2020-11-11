#include <stdio.h>
#include "myMath.h"


int main()
{
double userInput;
printf("Please insert a real number to calculate three functions: \n");
scanf("%lf",&userInput);

// Calculating the first function
double exponentResult = Exponent((int)userInput);
double powerResult = power(userInput,3);
float firstFuncResult = sub(add(exponentResult, powerResult), 2);
printf("The value of f(x) = e^x + x^3 - 2, at the %.4lf value, is: %.4f\n", userInput, firstFuncResult);

// Calculating the second function
powerResult = mul(power(userInput,2), 2);
double secondFuncFirstComponent = mul(userInput,3);
float secondFuncResult = add(secondFuncFirstComponent,powerResult);
printf("The value of f(x) = 3*x + 2*x^2, at the %.4lf value, is: %.4f\n",userInput, secondFuncResult);

// Calculating the third function
double numerator = (mul(power(userInput, 3), 4));
double theFraction = div(numerator, 5);
float thirdFuncResult = sub(theFraction, mul(userInput, 2));
printf("The value of f(x) = (4*x^3)/5 -2*x, at the %.4lf value, is: %.4f\n", userInput, thirdFuncResult);
return 0;
}