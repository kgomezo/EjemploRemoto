#include "nthprime.h"
#include <cmath>
#include <iostream>



long isprime(int m)
{
  int l=0;
  l=std::sqrt(m);
  if(m==1){
    return 0;
  }
  if(m==2) return 1;
  if(m==3) return 1;
  for(int ii = 2; ii <= l; ++ii) {

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

  std::cout <<"Probando que nthprime(1)==0 "<<"\n";
  assert(isprime(1) == 0 );
  std::cout <<"Probando que nthprime(10)==0 "<<"\n";
  assert(isprime(10) == 0);
  std::cout <<"Probando que nthprime(10)==0 "<<"\n";
  assert(isprime(10) == 0);
  std::cout <<"Probando que nthprime(29)==1 "<<"\n";
  assert(isprime(29) == 1);
  std::cout <<"Probando que nthprime(15485863) == 1 "<<"\n";
  assert(isprime(15485863) == 1);
  std::cout <<"Probando que nthprime(179424673) == 1 "<<"\n";
  assert(isprime(179424673) == 1);
  std::cout <<"Probando que nthprime(179424674) == 0 "<<"\n";
  assert(isprime(179424674) == 0);
  std::cout <<"Probando que nthprime(1000001) == 15485867 "<<"\n";
  assert(nthprime(1000001) == 15485867);
  std::cout <<"Probando que nthprime(1000002)==15485917 "<<"\n";
  assert(nthprime(1000002)==15485917);
 

}
