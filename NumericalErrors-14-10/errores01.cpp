#include <iostream>
int main(void)
{
  double a = 0.0;
  for (int ii=1; ii <= 10; ++ii) {
    a += 0.1;
  }
  std::cout.precision(17);
  std::cout.setf(std::ios::scientific);
  std::cout << a << "\n";

  return 0;
}
