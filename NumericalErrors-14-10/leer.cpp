#include<cstdlib>
#include<iostream>
#include<cstdio>

int main(){

  FILE * archivo;
  long medida;
  char * texto;
  archivo = fopen("datos.txt", "r");

  fclose(archivo);

        system("pause");
  return 0;
}
