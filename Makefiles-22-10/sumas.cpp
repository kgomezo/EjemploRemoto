#include<iostream>
#include<cmath>
//Comparar la suma armonica realizada de dos formas diferentes para mostrar
//las diferencias computacionales+

typedef float REAL;
REAL sumup(int N);
REAL sumdown(int N); //reciben el numero maximo de terminos

int main(void){
  std::cout.precision(6);
  std::cout.setf(std::ios::scientific); //que imprima con notacion cientifica

  for(int ii = 1; ii <1000; ++ii){
    REAL suma1= sumup(ii);
    REAL suma2 = sumdown(ii);
    std::cout << ii << "\t" << std::fabs(1- suma1/suma2) <<"\n";
  }
 
  return 0;
  
}

REAL sumup(int N){

  REAL suma = 0;
  for(int ii = 1 ; ii <=N; ++ii){
    suma += 1.0/ii;
  }
  return suma;
}

REAL sumdown(int N){ //suma desde el numero mas grande al mas pequeño 1/N + 1/(N-1)

  REAL suma =0;
  for(int ii = N; ii >= 1; --ii){ //va disminuyendo de N a 1
    suma += 1.0/ii; //estoy dividiendo en enteros. Estoy truncando, no lo aproxima, le quita la parte decimal
  }
  return suma;
}
