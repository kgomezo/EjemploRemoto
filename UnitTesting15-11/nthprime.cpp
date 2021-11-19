#include "nthprime.h"


long nthprime(long n){
  long counter = 0;
  for (int ii = 2; ii <= n  ; ++ii) {
    counter += isprime(ii);
    if (counter = n) return ii;
  }
  return counter;
}

long isprime(long m)
{
  for(int ii = 1; ii <= m; ++ii) {
    if (m%ii != 0) return 1;
    else return 0;
  }
  return 1;
}
