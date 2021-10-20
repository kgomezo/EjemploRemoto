// calcular el sin(x = pi/3), usando la expansion matematica
// sin(x, N) = \sum_{n=1}^{N} (-1)^{n-1} x^{2n-1}/(2n-1)!

#include <iostream>
#include <cmath>

typedef float REAL;
REAL mysin(REAL x, int N);

//double mysin(double x, int N); // declaration

int main()
{
    std::cout.setf(std::ios::scientific);
    std::cout.precision(10);

    const REAL x = M_PI/3; // +2M_PI da diferente. Fluctua mucho, los numeros son muy grandes
    const REAL exact = std::sin(x);

    for(int NMAX = 1; NMAX <= 1000; NMAX++) {
      REAL myval = mysin(x,NMAX);
      REAL diff = std::fabs(myval - exact)/exact; //hacerlo dos veces
      std::cout << NMAX << "\t" << myval <<"\t"  << diff << "\n";
    }

    return 0;
}

REAL mysin(REAL x, int N) // implementation
{
  //an+1 = (-1) x² an / ((2n+1)2n)
  std::fmod(x, 2*M_PI); //m%4 0%4 0. 1%4 1 -- 1/4 lo que sobra. 1/4= 0*4 +1
  // 2%4  2/4 = 0*4 +2 . cabe 0 veces y me sobra 2
  // 3%4 3/4 = 0*4 +3.
  // 5%4 5/4= 1*4 +1
  //Si x es menor que 0 sumarlo los pi hasta que quede en el intervalo x, 2mpi


  
  REAL an = x;
  REAL sum = 0.0;
  for(int n=1; n<= N; n++){ //n=2 ya pusimos el primer termino an=x. Se puede sum=an y n=2
    sum += an; //sumamos el primer termino
    an = ((-1)*x*x*an)/((2*n+1)*2*n);

  }
    return sum;
}
