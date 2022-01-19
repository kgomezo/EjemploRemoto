#include "mpi.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

void printdata(int *data, int N, int Nlocal);


int main(int argc, char **argv)
{
  const int N = std::atoi(argv[1]);
  int np, pid;
  int Nlocal=N/np;
  int tag =0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Status status;

    int *data = new int [N]{0};

    for(int ilocal=0; ilocal<Nlocal;++ilocal){

        for(int jlocal = Nlocal*pid; jlocal < Nlocal*(pid+1);++jlocal) {
            data[ilocal*(N+1)+jlocal]=1.0;
           

        }

    }

    if(pid ==0 ){
        printdata(data,N,Nlocal);
        for(int ipid=1; ipid < np;++ipid){
	  MPI_Recv(data,N, MPI_INT, ipid, tag, MPI_COMM_WORLD, &status);
            printdata(data,N,Nlocal);
        }
    } else {
      MPI_Send(data, N, MPI_INT, 0, tag, MPI_COMM_WORLD);
    }

   MPI_Finalize();

    return 0;
}
void printdata(int *data, int N, int Nlocal){

  for (int i=0; i<Nlocal;++i){
    for(int j=0; j<N; j++){
      std::cout << data[(i*N)+j]<<"\t";
    }
    std::cout<<"\n";
    }

  delete[] data;
}
