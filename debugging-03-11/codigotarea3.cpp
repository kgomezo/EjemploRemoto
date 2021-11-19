#include <iostream>
#include <cstdlib>
#include <cmath>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);

int main (int argc, char **argv)
{
  int ii, jj;
  ii =  2;
  jj = -1;
 
  std::cout << foo(ii,jj) << "\n" << foo(jj,ii) << "\n";
  std::cout << "funcion baz: " << baz(25.9) <<std::endl;
  //no tenia sentido llamarlas dos veces y una vez sin hacer nada, las calcularia dos veces las funciones
 

  return EXIT_SUCCESS;
}

int foo(int a, int b)
{
  if (a == 0 || b == 0 || bar(a,b) == 0) {
    return 0;
  }
  else {
    double n = ((a*1.00)/b) + ((b*1.00)/bar(a,b)) + ((b*1.00)/a);
    return n; }
    // return a/b + b/bar(a, b) + b/a; //está dividiendo por cero. Poner que si a es cero retorne Error. bar también puede ser error. Para que se haga un double
}

int bar(int a, int b)
{
  unsigned int c = a; //variable de tipo entero sin signo, positivo siemprel
  int g =0;
  g=(c+a-b); //le puse variable g, por organizacion
  return g;

}

double baz(double x)
{
  if (x = 0) {
    return 0;}  //le puse corchetes y el 0
  
  // double v = 1-(x+1);
  double r = sqrt(x);
  return r ; //le puse el ; y cambie std:: la puse en main, la variable v no se usa
}
