#include "mpi.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

void fill_matrix(data_t & data, int nrows, int ncols, int pid, int np);
void print_matrix(const data_t & data, int nrows, int ncols);


int main(int argc, char **argv)
{
  const int N = std::atoi(argv[1]);
  int np, pid;
  int Nlocal=N/np;
  int tag =0;

  data_t data = new double [Nlocal*N]{0.0};



    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Status status;



     MPI_Finalize();

    return 0;
}

void print_matrix(const data_t & data, int nrows, int ncols, int pid, int np){
    int tag = 0;
    if (0==pid){
        print_slab(data,nrows,ncols);

        data_t buffer = new double[nrows*ncols]{0.0};

        for(int src = 1; src < np;++src){
            MPI_Recv(&buffer[0], nrows*ncols, MPI_DOUBLE, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            print_slab(buffer,nrows,ncols);
        }
    }
    for (int i=0; i<Nlocal;++i){
        for(int j=0; j<N; j++){
          std::cout << data[(i*N)+j]<<"\t";
        }
        std::cout<<"\n";
    }
}
void fill_matrix(data_t & data, int nrows, int ncols, int pid, int np)
{
    for(int ilocal=0; ilocal < nrows; ++ilocal){
        int jlocal = nrows*pid + ilocal;
        data[ilocal*ncols + jlocal]=1.0;

    }
}
void print_slab(const data_t)
