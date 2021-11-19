# include <iostream>
# include <cstdlib>
# include <cmath>
# include <cassert>

long isprime(long m);
long nthprime(long n);
void test_prime(void);

int main(int argc, char *argv[])
{
  test_prime();
  const int n = std::atoi(argv[1]);
  if(n==0){
    std::cout<<"No hay números primos"<< "\n";
  }
   else{
      std::cout << nthprime(n) << "\n";
    }
  return 0;
}


long isprime(int m)
{

  for(int ii = 2; ii < m; ++ii) {
    if (m%ii == 0) {return 0; }}
   
  return 1;
}


long nthprime(long n)
{
  int counter = 0;
  for (int ii = 2;  ; ++ii) {
    counter += isprime(ii);
    if (counter == n) return ii;
  }
}
void test_prime(void){

  assert(isprime(1) == 1 );
  assert(isprime(10) == 0);
  assert(isprime(10) == 0);
  assert(isprime(29) == 1);
  assert(isprime(15485863) == 1);
  assert(isprime(179424673) == 1);
  assert(isprime(179424674) == 0);
  assert(nthprime(1000001) == 15485867);
  assert(nthprime(1000002)==15485917);

 }
