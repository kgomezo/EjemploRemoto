#include <omp.h>
#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <iostream>

template<typename T>
void print_elapsed(T & start, T & end);
int main(int argc, char *argv[]) {
    auto start = std::chrono::steady_clock::now();
    const int N = 80000000;
    int i;
    double *a = new double[N];
    auto end=std::chrono::steady_clock::now();

    start = std::chrono::steady_clock::now();
#pragma omp parallel for
    for(i = 0; i < N; i++) {
        a[i] = 2*i*std::sin(std::sqrt(i/56.7)) +
            std::cos(std::pow(i*i, 0.3));

    }

    std::cout << a[N] << "\n";

    delete [] a;
    end=std::chrono::steady_clock::now();
    print_elapsed(start,end);
    return 0;
}

template <typename T>
void print_elapsed(T & start, T & end )
{
  std::cout << "Elapsed time in ms: "
	    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
	    << "\n";
}
