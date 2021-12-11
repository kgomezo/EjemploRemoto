#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <chrono>

void suma(double * v, int init, int end, double & result);

int main(int argc, char **argv) {
  int N = std::atoi(argv[1]);
  int NTH = std::atoi(argv[2]);

  std::vector<double> res(NTH, 0.0);
  double * data = new double [N]{0.0};
  std::iota(data, data + N, 1.0);
  std::vector<std::thread> ths;

  int localsize = N/NTH; // 9/4 = 2
  for (int i = 0; i < NTH; i++) {
    int th_min_global_idx = localsize*i; // minimum global index for thread i //i=0 -> 0 ; i=1 -> 2!=3
    int th_max_global_idx = localsize*(i+1);
    if (N%NTH!=0 && i==NTH-1){ int th_max_global_idx = localsize*(i+1)+1;} // maximum global index for thread i. What happens if N%NTH != 0 ?
    // If N%NTH!=0 then the last thread works with one more element than the others(the residue)

    ths.push_back(std::thread(suma, data, th_min_global_idx, th_max_global_idx, std::ref(res[i])));
  }

  auto start = std::chrono::steady_clock::now();
  for (auto & th : ths) {
    th.join();
  }
  std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - start;

  std::cout << NTH << "\t" << elapsed.count() << "\n";
  std::clog << "accum = " << std::accumulate(res.begin(), res.end(), 0.0) << std::endl;
  return 0;
}

void suma(double * v, int init, int end, double & result)
{
  result = std::accumulate(v+init, v+end, 0.0);
}
