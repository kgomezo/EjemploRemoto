#include <iostream>
#include "nthprime.h"

int main(int argc, char *argv[])
{
  const int n = std::atoi(argv[1]);
  std::cout << nthprime(n) << "\n";

  return 0;
}
