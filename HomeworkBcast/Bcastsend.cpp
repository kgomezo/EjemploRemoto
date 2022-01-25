/*
#include "mpi.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <numeric>

void send_data_collective(int size, int pid, int np);

int main(int argc, char **argv)
{
  int np, pid;

  /* MPI setup */ /*
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  const int SIZE = std::atoi(argv[1]);
  send_data_collective(SIZE, pid, np);

  MPI_Finalize();

  return 0;
}

void send_data_collective(int size, int pid, int np)
{
  // create data buffer (all processes)
  double * data = new double [size];
  if (0 == pid) {
    std::iota(data, data+size, 0.0); // llena como 0 1 2 3 4
  }
  // send data to all processes
  int root = 0;
  double start = MPI_Wtime();

  if(0==pid){
      for (int src = 1; src < np; ++src){
          MPI_Send(&data[0], size, MPI_DOUBLE, src, 0, MPI_COMM_WORLD);
      }
  } else {
      MPI_Recv(&data[0], size, MPI_DOUBLE, root,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }
  double end = MPI_Wtime();
  // print size, time, bw in root
  if (0 == pid) {
    int datasize = sizeof(double)*size;
    std::cout << datasize << "\t" << (end-start) << "\t"
              << datasize/(end-start)/1.0e6 << "\n";
  }
  delete [] data;
}
*/

////////////////////
#include "mpi.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <numeric>

void send_data_collective(int size, int pid, int np);

int main(int argc, char **argv)
{
  int np, pid;

  /* MPI setup */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  const int SIZE = std::atoi(argv[1]);
  send_data_collective(SIZE, pid, np);

  MPI_Finalize();

  return 0;
}

void send_data_collective(int size, int pid, int np)
{
  // create data buffer (all processes)
  double * data = new double [size];
  if (0 == pid) {
    std::iota(data, data+size, 0.0); // llena como 0 1 2 3 4
  }
  // send data to all processes
  int root = 0;
  double start = MPI_Wtime();
  if (pid == root) { // If we are the root process, send our data to everyone
    for (int ii = 0; ii < np; ii++) {
      if (ii != root) {
        MPI_Send(&data[0], size, MPI_DOUBLE, ii, 0, MPI_COMM_WORLD);
      }
    }
  } else { // If we are a receiver process, receive the data from the root
    MPI_Recv(&data[0], size, MPI_DOUBLE, root, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
  }
  double end = MPI_Wtime();
  if (0 == pid) { // print size and bw in root
    int datasize = sizeof(double) * size;
    std::cout << size << "\t" << datasize / (end - start) / 1.0e6 << std::endl;
  }
  delete[] data;}
