#include <iostream>
#include <cstdlib>
#include <cmath>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);
void print_array(const double data[], const int & size);

int main (int argc, char **argv)
{
  int ii, jj;
  ii =  0; 
  jj = -1;
  //foo(ii, jj);la implementación de la funcion foo esta generando un floating oint porque ii=0
  //foo(jj, ii);
  // baz(25.9); 
  
  const int NX = 2, NY = 3, NZ = 4;
  // double *x, y[NY], z[NZ]; no se han inicializado los arreglos
  double *x, y[NY]={0, 0, 0}, z[NZ]={0, 0, 0, 0};
  x = new double [NX];
  x[0]=0;
  x[1]=0;
  //int ii, jj, kk; las variables ii y jj ya habían sido declaradas anteriormente. Y la variable kk no se utiliza  en el codigo
  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  std::cout << std::endl;
  
  for (ii = 0; ii < NX; ++ii) {
    // x[jj] = ii; Debería ser x[ii]
    x[ii]=ii;
  }
  //print_array(x, NZ); x no tiene la cantidad de elementos de NZ
  //print_array(y, NY); 
  //print_array(z, NZ + NY); z no tiene la cantidad de elemntos de NZ+NY
  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  std::cout << std::endl;

  for (jj = 0; jj < NY; ++jj) {
    //x[jj] = ii; estamos saliendonos del arreglo
    if(jj<NX)x[jj]=jj;
    y[jj] = jj;
  }
  //print_array(x-NY, NY); Estamos quitando un entero a un arreglo y además no coincide el número de elementos con el tamaño del arreglo 
  //print_array(y-NZ, NZ);
  //print_array(z + NZ + NY, NX);
  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  std::cout << std::endl;

  delete [] x;
  
  return EXIT_SUCCESS;
}

int foo(int a, int b)
{
  return a/b + b/bar(a, b) + b/a;
}

int bar(int a, int b)
{
  unsigned int c = a;
  return c + a - b;
}

double baz(double x)
{
  //if (x=0) return; No se está usando una condición si no una asignación y no se retorna nada
  if (x<0)return x;
  return std::sqrt(x);
    }

void print_array(const double data[], const int & size)
{
  std::cout << std::endl;
  for (int ii = 0; ii < size; ++ii) {
    std::cout << data[ii] << "  " ;
  }
}
