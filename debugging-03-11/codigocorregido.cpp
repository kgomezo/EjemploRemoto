#include <iostream>
#include <cstdlib>
#include <cmath>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);
void print_array(const double data[], const int & size);


int main (int argc, char **argv)
{
  int ii, jj; //cambiarle el nombre
  int kk=0;
  ii =  2; //le cambié el 0 para evitar la divisón por cero
  jj = -1;
  std::cout << foo(ii, jj)<< "\t " << foo(jj, ii)<< std::endl;
  //que imprima el resultado
  std::cout <<"Raíz de 25.9: " << baz(25.9)<<std::endl;

  const int NX = 2, NY = 3, NZ = 4;  //espacio. 
  double *x = NULL; //inicialicé el puntero
  double* y= NULL; //los cambié a punteros para que puedan cambiar de tamaño como se pretendía
  double* z=NULL;
  z = new double[NZ]; //tamaños iniciales que se quieren en los primeros arreglos
  y = new double [NY];
  x = new double [NX]; //new separa memoria que no esta inicializado.

  for (int mm = 0; mm < NX; ++mm){
    x[mm]=0; }
  for (int h = 0; h < NY; ++h){
    y[h]=0; }
  for (int j = 0; j < NZ; ++j){
    z[j]=0;} //inicializados, les doy valores iniciales a los componentes
  
  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  std::cout << " "  << std::endl; //le puse los " "
  delete[] x;
  delete[] y;
  delete[] z; //libero memoria, se quieren usar para nuevos arreglos con distintos tamaños
  
  y = new double [NY];
  z = new double [NZ+NY];
  x = new double [NZ]; //pido nueva memoria
  
  for (ii = 0; ii < NZ; ++ii) {
    x[ii] = ii; //no usa jj,le puse ii
  }
  for (int k=0; k< (NZ+NY); ++k){ //con los for vuelvo a darles valores con el espacio que se pidió para cada arreglo
    z[k]=0; }
  for (int u=0; u < NY; ++u){
    y[u] = 0;}
  
  print_array(x, NZ);
  print_array(y, NY);
  print_array(z, (NZ + NY));
  std::cout << " " << std::endl; //le puse " "
  delete[] x;
  delete[] y;
  delete[] z;
  //libero memoria
  //vuelvo a pedir espacio con los tamaños que se quiere
  x = new double [NY];
  y = new double [NZ];
  z = new double [NX];
 

  for (jj = 0; jj < NZ; ++jj) { //NZ porque  ahora tiene ese tamaño
    y[jj] = jj-NZ; //para reemplazar la resta que tenia en el printarray()
  }
  for (int ll = 0; ll < NY; ++ll){
    x[ll]= ll-NY;
  } //lo puse en un ciclo aparte ya que x[jj] no tiene el mismo numero de componentes que y
  for (kk = 0; kk < NX; ++kk){ //para reemplazar la suma en printarray
    z[kk]=kk + NZ +NY ;

  }
 
  print_array(x, NY);
  print_array(y, NZ);  //esta restando un array y un numero. Y tiene un numero menor de espacio que NZ, entra y saca un numero basura. Hay que modificar y
  print_array(z, NX);
  std::cout <<" " << std::endl;

  delete [] x;
  delete [] y;
  delete [] z;
  x = NULL; //vaciar para prevenir referencias de memoria invalidas
  y = NULL;
  z = NULL;

   return EXIT_SUCCESS;
}

int foo(int a, int b)
{
  if (a == 0 || b == 0 || bar(a,b) == 0) {
    return 0; //retorne cero si la division no esta definida
  }
  else {
    double n = ((a*1.00)/b) + ((b*1.00)/bar(a,b)) + ((b*1.00)/a);
    return n; }   //parentesis y ya que son double *1.00
}

int bar(int a, int b)
{
  unsigned int c = a;
  int g = (c+a-b);
  return g;   //parentesis, puse la operacion en una variable
}

double baz(double x)
{
 
  double vv= sqrt(x);
  return vv;      //ponerlo en otra variable, v no se usa así que la quité
}

void print_array(const double data[], const int & size) //overflow si size es mas grande
{ //para que se impriman por grupos, mas bonito :3
  const double *pointer[size];
  for (int ii = 0; ii < size; ++ii) { 
  
    pointer[ii] = &data[ii];
  }
  for (int ji = 0; ji < size; ++ji){ 

      std::cout << *pointer[ji] << "  " ;
      }
      std::cout<<" "<<std::endl;
  

}
