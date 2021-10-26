#include<iostream>
#include<cmath>

double S1 (int N);
double S2 (int N);
double S3 (int N);

int main(void){
  std::cout.precision(7);
  std::cout.setf(std::ios::scientific);

  for(int ii=1; ii < 100; ++ii){
    double suma1= S1(ii);
    double suma3= S3(ii);
    double suma2= S2(ii);
    std::cout << ii << "\t" << std::fabs(1-suma1/suma3) << "\t" << std::fabs(1-suma2/suma3) << "\n";
    
  }
  return 0;
}

double S1(int N){
  double suma=0;
  for(int ii=1; ii <= 2*N; ++ii){
    suma += std::pow(-1.0,ii)*(ii/(ii+1.0)) ;
  }
  return suma;
}

double S2(int N){
  double suma1 =0;
  double suma2 =0;
  double suma3 =0;
 
  for(int kk=1; kk <=N; ++kk){
    suma2 += 2.0*kk/(2.0*kk +1.0);
  }
  for(int ii=1; ii <= N; ++ii){
    suma1 += -(2.0*ii-1.0)/(2.0*ii);
  }
  suma3 += suma1+suma2;
  
  return suma3;
}

double S3(int N){
  double suma =0;
  for(int ii=1; ii <= N; ++ii){
    suma += (1.0/ (2.0*ii*(2.0*ii + 1.0)));
      }
  return suma;
}

    
