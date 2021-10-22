#include<iostream>
//Comparar la suma armonica realizada de dos formas diferentes para mostrar
//las diferencias computacionales+

typedef float REAL;
REAL sumup(int N);
REAL sumdown(int N); //reciben el numero maximo de terminos

int main(void){

  


  return 0;
  
}

REAL sumup(int N){

  REAL suma = 0;
  for(int ii = 1 ; ii <=N; ++ii){
    suma += 1/ii;
  }
  return suma;
}

REAL sumdown(int N){ //suma desde el numero mas grande al mas pequeño 1/N + 1/(N-1)

  REAL suma =0;
  for(int ii = N; ii >= 1; ++ii){
    suma += 1/ii;
  }
  return suma;
}
