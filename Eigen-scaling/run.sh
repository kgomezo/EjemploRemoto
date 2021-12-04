MSIZE=4000
REPS=10

# First section: running only with eigen
g++ -fopenmp -O3  eigen-matmul.cpp -o eigen.x
for nthreads in $seq(1 16); do
    echo -n "${nthreads}  ";
    OMP_NUM_THREADS=${nthreads} ./eigen.x ${MSIZE} ${REPS} 2>/dev//null
done > data_eigen.txt

# Second section: running with blas



# source .... spack?
spack load openblas
g++ -fopenmp -O3 -I $CMAKE_PREFIX_PATH/include -L $CMAKE_PREFIX_PATH/lib  eigen-matmul.cpp -DEIGEN_USE_BLAS -lopenblas -o eigen_blas.x
# complete here the remaining ...


spack unload openblas
