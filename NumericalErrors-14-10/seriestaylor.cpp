#include <iostream>
#include<cmath>

using namespace std;


int factorial(int x)  //calculates the factorial
{
    double fact = 1;
    for(; x >= 1 ; x--)
    {
        fact = x * fact;
    }
    return fact;
}

double power(double x,double n)  //calculates the power of x
{
    double output = 1;
    while(n>0)
    {
         output =( x*output);
         n--;
    }
    return output;
}

float sin(double n)  //value of sine by Taylors series
{
   double a,b,c;
   const double n = M_PI/3;
   float result = 0;
   for(int y=0 ; y!=9 ; y++)
   {
      a=  power(-1,y-1);
      b=  power(n,(2*y)-1);
      c=  factorial((2*y)-1);
      result = result+ (a*b)/c;
   }
   return result;
}

double output;


int main()
{
    const double n = M_PI/3;
    
    output = sin(n);

    cout<< "\nsine of the given value is\t"<< output;
    return 0;
}
