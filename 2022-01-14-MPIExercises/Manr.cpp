#include "mpi.h"
#include <iostream>
#include <cstdlib>
#include <eigen3/Eigen/Dense>

void IdentityMatrix(int reps, int pid, int np);

int main(int argc, char **argv)
{
  /* MPI Variables */
  int np, pid;

  /* MPI setup */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  const int N = std::atoi(argv[1]);
  IdentityMatrix(N, pid, np);

  /* finish */
  MPI_Finalize();

  return 0;
}

void IdentityMatrix(int N, int pid, int np)
{
  //En caso de no ser válido el uso de Eigen en MPI (debido a la indicación de usar arreglos unidimensionales), al final del código hay una parte comentada que se encarga de obtener el ejercicio para arreglos unidimensionales

  int Nlocal=N/np;
  Eigen::MatrixXd mat(Nlocal,N);






  mat.setZero();
  for(int i=0;i<Nlocal;i++){
      mat(i,(Nlocal*pid)+i)=1;

  }


  MPI_Status status;
  int tag = 0;
  int size=Nlocal*N;

  if(0==pid){//master




    std::cout<<mat<<"\n";









    for(int ipid=1;ipid<np;++ipid){
      double tstart = MPI_Wtime();
      MPI_Recv(&mat(0,0), size, MPI_DOUBLE, ipid, tag, MPI_COMM_WORLD, &status );
      double tend = MPI_Wtime();
      double total_time = tend - tstart;
      std::cout << "\t\t\t"<< "Ancho de banda:"<< sizeof(mat)/total_time/1.0e6 << std::endl;  // desconozco si sizeof() sirve para matrices de eigen, intenté usar mat.innerSize                                                                                                                                            // o algun otra funcion especial de eigen para conocer los bytes del objeto pero n                                                                                                                                            //o logré convencerme, igualmente es un numero constante por lo que no afecta en g                                                                                                                                            //eneral la curva,
      std::cout<<mat<<"\n";


    }
  }else{

      MPI_Send(&mat(0,0), size, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);
    }
}
