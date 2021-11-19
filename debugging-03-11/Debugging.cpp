#include <iostream>
#include <cstdlib>
#include <cmath>

void foo(int a, int b);
int bar(int a, int b);
void baz(double x);
void print_array(const double data[], const int &size);

int main(void) {
  int a = 0;            // Initialize a=0
  int b = -1;           // Initialize b=-1
  double c = 25.9;      // Initialize c=25.9

  foo(a, b);
  foo(b, a);
  baz(c);

  const int NX = 2, NY = 3, NZ = 4; // Length of arrays
  int i = 0;                        // Initialize i=0
  double *x = nullptr;              // Initialize pointer x as null pointer
  double y[NY] = {0};    // Define array y of size Ny, initialized in zero
  double z[NZ] = {0};    // Define array z of size Nz, initialized in zero
  x = new double[NX]{0}; // Ask for new memory, initialized in zero

  // First edition of arrays
  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  std::cout << std::endl;

  for (int ii = 0; ii < NX; ++ii) {
    x[ii] = ii;
  }

  // Second edition of arrays
  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  std::cout << std::endl;

  for (int jj = 0; jj < NX; ++jj) {
    x[jj] = i - NY;   // Change to x array for values i-NY
    z[jj] += NY + NZ; // Add to the first NXth inputs of z the value NY+NZ
  }
  for (int jj = 0; jj < NY; ++jj) {
    y[jj] = jj - NZ; // Change the value of y array for jj-NZ
  }

  // Third edition of arrays
  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NX);
  delete[] x; // Return memory
  x = nullptr;
  std::cout << std::endl;
  return EXIT_SUCCESS;
}

void foo(int a, int b) {
  /*-------------------------------------------------------
  foo:
  Calculate a/b + b/bar(a,b)+b/a if it is possible, where
  the division operator returns only quotient and the
  reminder is discarded.
  ---------------------------------------------------------
  Arguments:
    a:  Integer 1
    b:  Integer 2
  ---------------------------------------------------------
  If there is any division by zero, print the message:
    "Error: division by zero"
  Otherwise, print:
     ⌊a/b⌋+ ⌊b/bar(a,b)⌋+ ⌊b/a⌋
  -------------------------------------------------------*/
  int ba = bar(a, b);
  if (a == 0 || b == 0 || ba == 0) {
    std::cout << "Error: division by zero" << std::endl;
  } else {
    std::cout << a / b + b / ba + b / a << std::endl;
  }
}

int bar(int a, int b) {
  /*-------------------------------------------------------
  bar:
  Calculate the operation |a|+a-b.
  ---------------------------------------------------------
  Arguments:
    a:  Integer 1
    b:  Integer 2
  ---------------------------------------------------------
  Return:
     |a| + a - b
  -------------------------------------------------------*/
  unsigned int c = fabs(a);
  return c + a - b;
}

void baz(double x) {
  /*-------------------------------------------------------
  baz:
  If x is less than 0, then:
    return 0
  Otherwise:
    return the square root of x.
  ---------------------------------------------------------
  Arguments:
    x :   Double number.
  ---------------------------------------------------------
  If x <= 0:
    Return 0
  Otherwise,
    Return sqrt(x)
  -------------------------------------------------------*/
  if (x <= 0.) {
    std::cout << 0 << std::endl;
  } else {
    std::cout << std::sqrt(x) << std::endl;
  }
}
void print_array(const double data[], const int &size)
/*---------------------------------------------------------
print_array:
Print the components of a 1D array.
-----------------------------------------------------------
Arguments:
  data: 1D Array
  size: Size of data
---------------------------------------------------------*/
{
  std::cout << std::endl;
  for (int ii = 0; ii < size; ++ii) {
    std::cout << data[ii] << "  ";
  }
}
