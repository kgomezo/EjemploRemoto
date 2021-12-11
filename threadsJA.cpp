#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <chrono>

void suma(double * v, int init, int end, double & result);
int choose(int & residue);

int main(int argc, char **argv) {
  int N = std::atoi(argv[1]);
  int NTH = std::atoi(argv[2]);

  std::vector<double> res(NTH, 0.0);
  double * data = new double [N]{0.0};
  std::iota(data, data + N, 1.0);
  std::vector<std::thread> ths;

  int localsize = N/NTH;
  int residue = N%NTH; 
  int aux=0;
  int extra=0;
  for (int i = 0; i < NTH; i++) {
    extra=choose(residue);//es 1 si residue es mas que cero y cada vez que se llama la funcion se resta 1 a residue(ver la funcion)
    int th_min_global_idx = i*(localsize)+aux;
    int th_max_global_idx = (i+1)*(localsize)+extra+aux; // dejo N%NTH threads con un dato demás y el resto con solo N/NTH. Por ejemplo: 11/4=2 y 11%4=3, entonces de los 4 threads habrán 3 con 3 datos y uno con 2 datos.
    ths.push_back(std::thread(suma, data, th_min_global_idx, th_max_global_idx, std::ref(res[i])));
    if(extra==1)aux+=1;
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

int choose(int & residue)
{
  if(residue>0){
    residue-=1;
    return 1;
  }
  else return 0;
}
