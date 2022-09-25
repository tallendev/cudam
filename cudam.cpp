#include "safecuda.h"

__host__ void * operator new(std::size_t n) //throw(std::bad_alloc)
{
    void* p;
    cudaMallocManaged(&p, n);
    CHECK_CUDA_ERROR();
    return p;
}


__host__ void operator delete(void* p) //throw()
{
    cudaFree(p);
    CHECK_CUDA_ERROR();
}


__host__ void * operator new[](std::size_t n) //throw(std::bad_alloc)
{
    void* p;
    cudaMallocManaged(&p, n);
    CHECK_CUDA_ERROR();
    return p;
}


__host__ void operator delete[](void* p) //throw()
{
    cudaFree(p);
    CHECK_CUDA_ERROR();
}
