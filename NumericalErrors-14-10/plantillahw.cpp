#include<iostream>
#include <cmath>
#include<stdlib.h>
#include<math.h>
//calcular el sin(x=pi/3), usando la expansion matematica
//sin (x,y) = \sum_{n=1}{N} (-1){n-1} x{2n-1}/(2n-1)!

double mysin(double x, int N);
int fact(int a);

int main(){
  std::cout.setf(std::ios::scientific);
  std::cout.precision(6);

  const double x = M_PI/3;
  const double exact = std::sin(x);

  for(int NMAX = 1; NMAX <= 1000; NMAX ++){
    double diff = std::fabs(mysin(x, NMAX)-exact)/exact;
    std::cout << NMAX <<"\t" << diff <<"\n";
  }
  return 0;
}
int fact(int a){
  int F=1;
  for(int i=1; i<= a; i++){
    F=F*i;
  }
  return F;
}

double mysin(double x, int N)
{
  double seno=0;
  for (int n=0; n<= N; ++n)
    {
      seno= seno + (std::pow(-1,n-1))*(std::pow(x,(2*n)-1))/(fact((2*n)-1));
    }

  return seno;
}
