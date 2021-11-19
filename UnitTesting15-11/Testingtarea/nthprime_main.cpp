#include <iostream>
#include "nthprime.h"

int main(int argc, char *argv[])
{
  const int n = std::atoi(argv[1]);
  if(n==1){
std::cout<<"No hay números primos"<<"\n";
  }
else{
  std::cout << nthprime(n) << "\n";
}
  return 0;
}
