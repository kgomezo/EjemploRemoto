#include <iostream>
int main()
{
  float xover = 1.23e40;
  float xunder = 1.23e-50;

  std::cout <<"xover = " <<xover <<"\n";
  std::cout <<"xunder = " <<xunder <<"\n";

  int m = 5000000000;
  int n=  2000000000;
  std::cout << "m = " << m << "\n";
  std::cout << "n = " << n << "\n";

  return 0;
}
