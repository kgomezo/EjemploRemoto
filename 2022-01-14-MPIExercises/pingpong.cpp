#include "mpi.h"
#include <stdio.h>
#include <iostream>

int main(int argc, char **argv){
    int id=0, np=0, tag=0, suma=0, temp=0;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    if(id==0){
        MPI_Send(&id, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
    }
    else{
        MPI_Recv(&temp,1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status); //si es 1 1 estoy recibiendo de mi mismo
        temp += 99;
    }
    if(id==1){
        MPI_Send(&temp, 1, MPI_INT, 0, tag, MPI_COMM_WORLD); //destination es en cero

    }
    else{
        MPI_Recv(&temp, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &status);
        std::cout<<temp <<"\n";
    }
/* temp es el buffer. En el cero estoy esperando algo desde el 1 */
            MPI_Finalize();

}
