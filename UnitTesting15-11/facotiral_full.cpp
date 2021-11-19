#include <iostream>
#include <cstdlib>

// TODO : add test

int factorial(int n);

void test(void); //que guarde las correcciones

int main(int argc, char **argv) 
{
  test();
  const int N = std::atoi(argv[1]);

  std::cout << factorial(N) << std::endl;

  return 0;
}


int factorial(int number)
{
    return number <= 1 ? number : factorial(number-1)*number;
}

void testing(void){
  assert(factorial(0) == 1); //se puedehacer un if. assert verifica que eso ocurre
}
